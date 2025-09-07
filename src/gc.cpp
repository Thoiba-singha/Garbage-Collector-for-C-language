
//                     ----------- This is the official GC [ Author Vector [ M. Thoiba Singha] ] ---------------
// 
//                     ----------- Cross-compiler supported GNU/GCC || Clang || MSVC  --------------------------

// src/gc.cpp
#include <iostream>
#include <memory>
#include <cstddef>

// Custom deleter that logs when memory is freed
struct DebugDeleter {
    void operator()(char* ptr) const {
        std::cout << "[C++ backend] Freed memory\n";
        delete[] ptr;
    }
};

extern "C" {

    // Static unique_ptrs to hold allocations
    static std::unique_ptr<char[], DebugDeleter> malloc_buffer;
    static std::unique_ptr<char[], DebugDeleter> calloc_buffer;

    // custom_malloc: allocate sz bytes
    void* gc_malloc(size_t sz) {
        malloc_buffer.reset(new char[sz]);

        // Initialize memory (optional)
        for (size_t i = 0; i < sz; i++)
            malloc_buffer[i] = 0;

        //std::cout << "[C++ backend] Allocated " << sz << " bytes (malloc)\n";
        return malloc_buffer.get();
    }

    // custom_calloc: allocate count*sz bytes and initialize to zero
    void* gc_calloc(size_t count, size_t sz) {
        size_t total = count * sz;
        calloc_buffer.reset(new char[total]);

        // Initialize memory to zero
        for (size_t i = 0; i < total; i++)
            calloc_buffer[i] = 0;

        //std::cout << "[C++ backend] Allocated " << total << " bytes (calloc)\n";
        return calloc_buffer.get();
    }

}
