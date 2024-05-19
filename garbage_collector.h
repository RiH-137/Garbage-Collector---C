#ifndef garbage_collector_h
#define garbage_collector_h

#include<stdbool.h>

typedef struct Object {
    bool marked;
    struct Object* next;
    
} 
Object;


typedef struct {
    Object* head;
} 
Heap;

/*
lets create a function named createHeap(). It returns a pointer to a Heap structure.
 This function will be responsible for creating a new heap.


*/
Heap* createHeap();

//responsible for allocating a new object on the heap
Object* allocateObject(Heap* heap);

//responsible for performing garbage collection on the heap.
void garbageCollect(Heap* heap);

#endif 
