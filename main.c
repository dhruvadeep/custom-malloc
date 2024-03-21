// Author: Dhruvadeep Malakar
// Reference: https://www.youtube.com/watch?v=sZ8GJ1TiMdk&t=171s

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

// Define the capacity of the heap
#define CAPACITY 1000

char heap[CAPACITY] = {0}; // The heap

// simple linear allocator
size_t heap_size = 0; // The current size of the heap


// heap_alloc: allocate a block of memory of size bytes
// Allocates a block of size bytes from the heap and returns a pointer to the block
void *heap_alloc(size_t size) // returns a pointer 
{
    assert(heap_size + size <= CAPACITY); // check if heap has enough space
    void *result = heap_size + heap; // pointer to the block
    heap_size += size; // update the heap size
    return result;

}

// heap_free: free the memory block pointed to by ptr
// Deallocates the space previously allocated by heap_alloc
void heap_free(void *ptr) // takes a pointer
{
    (void) ptr; // suppress unused parameter warning 
    assert(false && "Not implemented yet");
}

// Garbage collection
void heap_collect()

{
    assert(false && "Not implemented yet");
}







// MAIN FUNCTION
int main()
{
    char *root = heap_alloc(26); // allocate 26 bytes

    // Iterate over the heap and print the contents
    for (int i = 0; i < 26; i++)
    {
        root[i] = 'A' + i; // store the alphabet A,B,...
    }

    return  0;
}


