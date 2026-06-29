#include "history.h"
#include <stdlib.h>
#include  <stdio.h>
#include <string.h>

char *my_strcpy(char *dest, const char *src){
    const char *ptr = src;
    char *ptr2 = dest;
    char c;
    do{
        c = *ptr;
        *ptr2 = c;
        ptr++;
        ptr2++;
    }while(c != '\0');
    return dest;
}

void add(History *h, char *command){
    //add a node in the empty list
    Node *node = malloc(sizeof(Node)); // node lives on heap
    if(h -> head == NULL){
        char *command_str = (char *)malloc(strlen(command) + 1); // allocate memory
        my_strcpy(command_str,command); // copy the string
        node -> command = command_str;
        node -> prev = NULL; // set prev to null
        node -> next = NULL; // set next to null
        h -> head = node;
        h -> tail = node;
        h -> current = node;
    }else{ // add a node in non empty list
        char *command_str = (char *)malloc(strlen(command) + 1);
        my_strcpy(command_str,command);
        node -> prev = h -> tail;
        node -> next = NULL;
        node -> command = command_str;
        h -> tail -> next = node;
        h -> tail = node;
        h -> current = node;
    }
}

void back(History *h){
    if(h -> current -> prev != NULL){ // check if the history's current has anything written previously
        h -> current = h -> current -> prev; // if something is written before the current command then move back to that previous command
    }
}

void forward(History *h){
    if(h -> current -> next != NULL){
        h -> current = h -> current -> next; 
    }
}

void print_all(History *h){
    Node *ptr = h -> head;
    while(ptr != NULL){
        printf("%s\n",ptr -> command);
        ptr = ptr -> next;
    }
}

void cleanup(History *h){
    Node *ptr = h -> head;
    while(ptr != NULL){
        free(ptr -> command);
        Node *temp_next = ptr -> next; 
        free(ptr);
        ptr = temp_next;
    }
}
