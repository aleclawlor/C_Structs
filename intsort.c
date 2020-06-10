// reads in a sequence of positive integers and saves each one in a sorted chain of nodes
// input value -1 indicates end of input
// when -1 is entered, traverse the chain and print the integers in sorted order

#include "intsort.h"
#include <stdio.h>
#include <stdlib.h>

// global variable for first node
IntNode *first = NULL;
IntNode *createNode(int val){
    // temporary pointer to the node we just created
    IntNode * new_node;
    new_node = malloc(sizeof(struct intnode));

    // store the data value in the value member of the new node
    // dereference the memory allocation of new_node to get access to the struct at that location
    new_node -> item = val;
    return new_node;
}

// insert a node into the chain, in sorted order
void insert(IntNode *header, int val){

    IntNode * new_node = header;

    // if first is null 
    if(first == NULL){
        new_node -> next = first;
        first = new_node;
        return;
    }

    // traverse through list until we get to a node whose current value is less than the value we're inserting
    IntNode * curr = first;

    // used in an edge case where the second item was bigger than the first and it messed up the order
    if(val < first -> item){
        new_node -> next = first;
        first = new_node;
        return;
    }

    while (curr -> next != NULL){
        
        IntNode * next = curr -> next;
        // this is where we want to insert the new node
        if(curr -> item <= val && next -> item >= val){
            // we want to make the new node point to the next
            // and we want to make the current node point to the new node
            // no reason to change the 'next' value of next
            curr -> next =  new_node;
            new_node -> next = next;
            return; 
        }
        curr = next;
        // otherwise, move to the next pointer
    } 
    // if we've made it this far, this means we're at the end
    // in this case, we want to set the next of the current block to this block
    curr -> next = new_node;
    return;
}

// print the values stored in the chain of nodes
void printAll(IntNode *header){
    if (header == NULL){
        printf("The list is empty!");
        return;
    }
    IntNode * curr = first;
    int i = 0;

    // using curr -> next instead blocks the -1 from being written
    while(curr != NULL){
        printf("%d at position %d in linked list\n", curr -> item, i);
        curr = curr -> next;
        i++;
    }
    
}

int main(){
    
    printf("Please enter numbers and mark the end of the sequence with a -1: \n");
    
    int current;
    while(current != -1){
        scanf("%d", &current);
        if (current == -1){
            continue;
        }
        // create a new IntNode structure for the current value
        IntNode * newNode = createNode(current);
        insert(newNode, current);   
    }

    printAll(first);
    return -1; 
}

