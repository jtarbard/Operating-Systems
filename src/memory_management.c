#include "memory_management.h"
#include <unistd.h>
#include <stdio.h>
#include <unistd.h>

//Doubly linked list: stores block structure
//TODO: expand upon basic linked list with necessary variables
struct Node {
    int size_t;

    struct Node* prev;
    struct Node* next;
};
struct Node* head;

//TODO: map requirements on paper to build from
void * _malloc(size_t size){

    if(size == 0) {
        return NULL;
    }
    else {
        return sbrk(size);
    }
}
//TODO: map requirements on paper to build from
void _free(void * ptr){

}

