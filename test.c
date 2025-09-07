
// test.c

#include <stdio.h>
#include "gc.h"

typedef struct Node {
    int* id;
    int* value;
}Node;
int main() {

    {

        Node* node = gc_malloc(sizeof(Node));
        node->id = gc_malloc(sizeof(int));
        node->value = gc_malloc(sizeof(int));
        int* a = (int*)gc_malloc(sizeof(int));
        *a = 55;

        int* b = (int*)gc_calloc(5, sizeof(int));


    }
    printf("Program exit\n");

    // No free required in C
    return 0;
}
