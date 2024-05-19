#include "garbage_collector.h"
#include <stdlib.h>

// create a new heap
Heap* createHeap() {
    Heap* heap = (Heap*)malloc(sizeof(Heap));
    heap->head = NULL;                              //heap pointer points toward head and head store NULL
    return heap;
}

// allocating a new object in the heap
Object* allocateObject(Heap* heap) {
    Object* obj = (Object*)malloc(sizeof(Object));
    obj->marked = false;
    obj->next = heap->head;
    heap->head = obj;
    return obj;
}

// marking an object and recursively mark all reachable objects
void mark(Object* obj) {
    if (obj == NULL || obj->marked) return;
    obj->marked = true;
    
}

// marking all objects in the heap
void markAll(Heap* heap) {
    for (Object* obj = heap->head; obj != NULL; obj = obj->next) {
        mark(obj);
    }
}

// sweeping or deleting unmarked objects and free their memory
void sweep(Heap* heap) {
    Object** obj = &heap->head;
    while (*obj) {
        if (!(*obj)->marked) {
            Object* unreached = *obj;
            *obj = unreached->next;
            free(unreached);
        } else {
            (*obj)->marked = false;
            obj = &(*obj)->next;
        }
    }
}

// perform garbage collection
void garbageCollect(Heap* heap) {
    markAll(heap);
    sweep(heap);
}
