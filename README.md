# 📦 Garbage Collector in C !

RAII-Based Automatic Memory Management Solution for C Language

## 📖 Overview
`gc_malloc` `gc_calloc` are custom automatic memory management functions for the C language, offering safe, robust, and leak-free memory allocation routines. The backend is implemented in modern C++ leveraging **RAII (Resource Acquisition Is Initialization)** principles to ensure automatic deallocation of allocated memory without manual `free` calls on the C language client side.

This library provides C-compatible interfaces for:
- `gc_malloc` — Safe memory allocation || Pure RAII, NO REALLOC SUPPORTED.
- `gc_calloc` — Safe memory allocation with initialization || Pure RAII, NO REALLOC SUPPORTED.

⚠️ Note:  
This Garbage collector is designed exclusively for the **RAII based cleanup** and it **dont support realloc/resizing** at this stage.

## 🚀 Features
- ✅ Automatic deallocation on scope exit via RAII.
- ✅ C-compatible API, backed by a modern C++ implementation.
- ✅ Safe and predictable memory management routines.
- ✅ No manual `free()` needed on the client side.
- ✅ Simple, clean, and minimal API surface.
- ✅ Cross-Compiler supported **MSVC || GNU/GCC || Clang**.



**Example usage:**
```c
#include "gc.h" // standard header file
#include <stdio.h>

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
        printf("a value: %d", *a);
        int* b = (int*)gc_calloc(5, sizeof(int));
    }
    printf("Program exit\n");

    // No free required
    return 0;
}
```


## Future Improvements
- Implement a more sophisticated strategy (e.g., reference counting, ownership transfer).
- Add thread safety for parellel multithreaded executions and improve performance.
- Add debugging tools for memory tracking, leak detection etc.



