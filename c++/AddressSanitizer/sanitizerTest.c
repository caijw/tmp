/*
clang-9 -g -fsanitize=address -fno-omit-frame-pointer -w sanitizerTest.c

-fsanitize=leak

ASAN_OPTIONS=suppressions=MyASan.supp ./a.out
*/

int foo(){
  double bar[] = {7,8};
  return bar[3];
}

int __attribute__((no_sanitize("address"))) foo1(){
  double bar[] = {7,8};
  return bar[3];
}


int main(){
  return foo1();
}