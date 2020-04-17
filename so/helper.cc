#include <iostream>


#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C
#endif

#if defined(SHARED_LIB)
#define EXPORT                                                            \
  EXTERN_C __attribute__((visibility("default"))) __attribute((used))
#else
#define EXPORT EXTERN_C
#endif

int num = 0;

EXPORT int getNum() {
    return num;
}

EXPORT void setNum(int _num) {
    num = _num;
}
