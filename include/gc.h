
#ifndef GC_H
#define GC_H

#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

	void* gc_malloc(size_t sz);
	void* gc_calloc(size_t count, size_t sz);

#ifdef __cplusplus
}
#endif

#endif // GC_H
