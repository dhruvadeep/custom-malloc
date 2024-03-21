// Author: Dhruvadeep Malakar
// Reference: https://www.youtube.com/watch?v=sZ8GJ1TiMdk&t=171s

#include <assert.h>
#include <stdio.h>
#include <stdbool.h>

// Define the capacity of the heap
#define CAPACITY 1000
#define HEAP_ALLOCED_MAX 100

// Define the block structure
// Type of fragment in the heap
typedef struct
{
    void *start; // start of the block
    size_t size; // size of the block
    bool is_free; // is the block free?
} block_t;


char heap[CAPACITY] = {0}; // The heap

// Keeping track of the blocks
block_t heap_allocations[HEAP_ALLOCED_MAX] = {0}; // [
size_t heap_allocations_count = 0; // number of blocks allocated

// simple linear allocator
size_t heap_size = 0; // The current size of the heap


// heap_alloc: allocate a block of memory of size bytes
// Allocates a block of size bytes from the heap and returns a pointer to the block
void *heap_alloc(size_t size) // returns a pointer 
{
    assert(heap_size + size <= CAPACITY); // check if heap has enough space
    void *result = heap_size + heap; // pointer to the block
    heap_size += size; // update the heap size
    
    
    // Metadata for the block
    block_t chunk = {
        .start = result,
        .size = size,
        .is_free = false
    };

    assert(heap_allocations_count <= HEAP_ALLOCED_MAX); // check if heap_allocations has enough space
    // Add the block to the heap_allocations
    // Currently how many blocks are allocated + 1
    heap_allocations[heap_allocations_count++] = chunk;
    
    
    return result;

}

// Dump the heap with the block metadata
void heap_dump_alloced_chunks(void) 
{
    for (size_t i = 0; i < heap_allocations_count; i++)
    {
        printf(" start: %p, size: %zu, is_free: %s\n",
               heap_allocations[i].start,
               heap_allocations[i].size,
               heap_allocations[i].is_free ? "true" : "false");
    }
    
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

    heap_dump_alloced_chunks(); // dump the heap
    // heap_free(root); // free the memory block

    return  0;
}


