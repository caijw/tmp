#define DART_SHARED_LIB

#include "include/dart_api_dl.h"
#include <iostream>

DART_EXPORT void RunFinalizer(void *isolate_callback_data,
                              Dart_WeakPersistentHandle handle,
                              void *peer)
{
  std::cout << "RunFinalizer, peer: %p" << peer << std::endl;
}

// 给某个 handler 添加一个 weak persistent handle
// 该函数会抛出异常，调用者需要进行 try
DART_EXPORT int test_weak_persistent_handle(Dart_Handle h, void* peer, intptr_t callback_address)
{
  enum ErrCode {
    OK = 0,
    ERR_NEW_WEAK_PERSISTENT_HANDLE = 1,
  };
  
  Dart_WeakPersistentHandleFinalizer callback = (Dart_WeakPersistentHandleFinalizer)(callback_address);
  auto weak_handle = Dart_NewWeakPersistentHandle_DL(
      h, peer, 0, callback);
  if (!weak_handle) {
      fprintf(stderr, "can not make weak persistent handle.\n");
      return ErrCode::ERR_NEW_WEAK_PERSISTENT_HANDLE;;
  }
  return ErrCode::OK;
}
