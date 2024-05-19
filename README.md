Try to build a GARBAGE COLLECTOR for C programming language.

1. Understanding Garbage Collection
Garbage collection is like cleaning up after yourself automatically. In programming, when you create objects or allocate memory, you need to make sure you clean up after yourself when you're done using them. If you forget to clean up, it can lead to memory leaks, where memory is allocated but never freed, causing your program to use more and more memory over time.


2. Memory Management in C
In C, you usually have to manage memory manually. This means you need to allocate memory when you need it using functions like malloc() and free it when you're done using free(). It's like borrowing a book from the library—you need to return it when you're done, or the library will run out of space.


3. Creating a Garbage Collector
To make a garbage collector, you need to create a system that automatically finds and frees memory that is no longer being used by your program. Here's how you can do it:

**Mark-and-Sweep Algorithm**
One common way to create a garbage collector is to use a technique called the mark-and-sweep algorithm:

Mark: First, you go through all the memory you've allocated and mark each piece of memory as either "in use" or "not in use". It's like putting sticky notes on books in a library to see which ones are still being read.

Sweep: Next, you go through all the memory again and free up the memory that wasn't marked as "in use". It's like removing books from the library that nobody is reading anymore.


4. Implementing the Garbage Collector
a. Data Structures
You'll need data structures to keep track of allocated memory. For example, you might use a linked list to store pointers to allocated memory blocks.

b. Allocation and Deallocation Functions
You'll need functions to allocate memory (like malloc()) and to deallocate memory (like free()). These functions will also update your data structures accordingly.

c. Garbage Collection Function
You'll need a function to perform the mark-and-sweep algorithm. This function will mark all reachable memory blocks (ones that your program can still access) and then sweep through and free up the memory blocks that weren't marked.

5. Using the Garbage Collector
   Once you've created your garbage collector, you can use it in your program by calling the allocation and deallocation functions provided by the garbage collector instead of malloc() and free().


6. Testing and Optimization
Finally, you'll want to test your garbage collector to make sure it works correctly and optimize it for performance if needed.



Note:- ".o" file, also known as an object file, is a compiled binary file that contains machine code generated from the corresponding source code file.
        ".a" file is an archive file that contains one or more object files (usually ".o" files) bundled together. 

**How to run this code on your local system?**
step1> Clone this project.
step2> open terminal and run....
        1. gcc -c garbage_collector.c -o garbage_collector.o
        2. ar rcs libmy_gc.a garbage_collector.o
        3. gcc test.c -Iinclude -L. -lmy-gc -o test
        4. ./test
        5. Import in your desired project--> #include "garbage_collector"



