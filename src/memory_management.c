#include "memory_management.h"
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

//Doubly linked list: stores block structure
//TODO: expand upon basic linked list with necessary variables
typedef struct block {
    int free_t; //status of to whether the block is populated

    int size_t; //remaining space in block
    char* address_t; //holder for sbrk return address

    //struct block* prev;
    struct block* next; //previous block
} block_t;

//Declare structs
block_t *head = NULL;
block_t *block_head;

block_t *pointer;
block_t *new_pointer;

void new_block(size_t size){
    block_head = sbrk(sizeof(block_head));
    if(size > 0) { //populated block
        block_head->free_t = 0;
    }
    else{ //freed block
        block_head->free_t = 1;
    }
    block_head->size_t = 4000 - sizeof(block_head);
    block_head->address_t = sbrk(0);
    //TODO: next - consider that insertion may happen in the middle or end
    if(pointer == head){
        block_head->next = head;
        head = block_head;
    }
    else{
        block_head->next = pointer->next;
        pointer->next = block_head;
    }

    return NULL;
}

void * _malloc(size_t size){
    //Initialise head
    if(head == NULL){
        //create first block header
        block_head = sbrk(sizeof(block_head));
        block_head->free_t = 0;
        block_head->size_t = 4000 - sizeof(block_head);
        block_head->address_t = sbrk(0);
        block_head->next = head;
        //update head
        head = block_head;
    }
    if(size != 0){
        pointer = head;

        //Todo: Fix loop, currently breaking tests with segmentation fault
//        while(pointer){
//
//            if(pointer->free_t == 1){
//                new_block(size);
//            }
//            else if(pointer->size_t >= size){
//                new_block(size);
//            }
//
//            pointer = pointer->next;
//        }

        new_block(size);
        return sbrk(0);
    }
    else{
        return NULL;
    }

}

void _free(void * ptr){
    sbrk(-sizeof(ptr));
}

