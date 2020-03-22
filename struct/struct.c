#include <stdio.h>
#include <stdlib.h>

struct B;

struct _B
{
    int _b;
};

int main() {
    struct _B *_bPtr = calloc(1, sizeof(struct _B));
    _bPtr->_b = 100;
    struct B *bPtr = (struct B *)_bPtr;
    // printf("bPtr->_b: %d\n", bPtr->_b); // error: dereferencing pointer to incomplete type ‘struct B’
    printf("_bPtr->_b: %d\n", _bPtr->_b);
    return 0;
}
