import 'dart:ffi';
import 'package:ffi/ffi.dart';
import 'dylib_utils.dart';


final testLibrary = dlopenPlatformSpecific("ffi_test", path: "build/" );
main() {

  final initializeApi = testLibrary.lookupFunction<IntPtr Function(Pointer<Void>),
      int Function(Pointer<Void>)>("Dart_InitializeApiDL");
  if (initializeApi(NativeApi.initializeApiDLData) != 0) {
    throw "Failed to initialize Dart API";
  }

  print(NativeApi);
  print(NativeApi.initializeApiDLData);
final test_weak_persistent_handle = testLibrary.lookupFunction<Int32 Function(Handle, Pointer<Uint8>),
    int Function(Object, Pointer<Uint8>)>("test_weak_persistent_handle");

final finalizer = testLibrary.lookupFunction<Int32 Function(Handle, Pointer<Uint8>),
    int Function(Object, Pointer<Uint8>)>("test_weak_persistent_handle");

  print("hello");

  {
    var a = "hello world";
    var b = 1;
    Pointer<Uint8> peer = allocate<Uint8>(count: 1);
    int ret = test_weak_persistent_handle(a, peer);
    if (ret != 0) {
      print("test_weak_persistent_handle fail");
      print(ret);
    }

  }
  print("good bye");

}
