#include <stdio.h>
#include <stdlib.h>

typedef struct B B;

struct _B
{
    int _b;
};

typedef struct _B _B;

int main() {
    _B *_bPtr = calloc(1, sizeof(_B));
    _bPtr->_b = 100;
    B *bPtr = (B *)_bPtr;
    // printf("bPtr->_b: %d\n", bPtr->_b); // error: dereferencing pointer to incomplete type ‘struct B’
    printf("_bPtr->_b: %d\n", _bPtr->_b);
    return 0;
}
