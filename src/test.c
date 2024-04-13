#include <sys/mman.h>

#include "test.h"
#include "mem.h"

void usual_test()
{
    void* heap = heap_init(500);
    debug_heap(stdout, heap);
    _malloc(1);
    _malloc(400);
    debug_heap(stdout, heap);

}

void free_test()
{
    void* heap = heap_init(500);
    void *ptr = _malloc(200);
    _malloc(200);
    debug_heap(stdout, heap);
    _free(ptr);
    debug_heap(stdout, heap);
}

void free_test2(){
    void* heap = heap_init(500);
    void* ptr1 = _malloc(100);
    _malloc(100);
    void* ptr2 = _malloc(100);
    debug_heap(stdout, heap);
    _free(ptr1);
    _free(ptr2);
    debug_heap(stdout, heap);
}

void new_region_test(){
    void* heap = heap_init(10000);
    _malloc(5000);
    debug_heap(stdout, heap);
    _malloc(10000);
    debug_heap(stdout, heap);
}

static void* map_pages_copy(void const* addr, size_t length, int additional_flags) {
    return mmap( (void*) addr, length, PROT_READ | PROT_WRITE, additional_flags , 0, 0 );
}

void new_distant_region_test(){
    void* heap = heap_init(8096);
    _malloc(100);
    debug_heap(stdout, heap);
    map_pages_copy(heap, 10000, 0);
    _malloc(10000);
    debug_heap(stdout, heap);


}