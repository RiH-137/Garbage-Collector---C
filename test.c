#include <stdio.h>
#include <stdlib.h>
#include "garbage_collector.h"

void manualMemoryManagement() {
    //allocating memory manually
    printf("Manual Memory Management:\n");
    Object* obj1 = (Object*)malloc(sizeof(Object));
    Object* obj2 = (Object*)malloc(sizeof(Object));
    Object* obj3 = (Object*)malloc(sizeof(Object));

    // Simulate program operations
    obj2 = NULL;

    // manually free memory 
    free(obj1);
    
    // memory leak
    free(obj3);

    printf("Manual memory management complete.\n\n");
}

int main() {
    
    manualMemoryManagement();
    //manual memory management 

    // Now using garbage_collector.h
    printf("Using Garbage Collector:\n");
    Heap* heap = createHeap();

    Object* obj1 = allocateObject(heap);
    Object* obj2 = allocateObject(heap);
    Object* obj3 = allocateObject(heap);

    // Simulate program operations
    obj2 = NULL;

    // performing garbage collection
    garbageCollect(heap);

    // continue program logic
    printf("Garbage collection complete.\n");

    // free remaining objects before exiting
    garbageCollect(heap);
    free(heap);

    return 0;
}
