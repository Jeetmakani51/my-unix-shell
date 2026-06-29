#ifndef HISTORY_H
#define HISTORY_H

typedef struct Node{
    struct Node *next;
    struct Node *prev;
    char *command;
}Node;

typedef struct{
    Node *head;
    Node *current;
    Node *tail;
}History;

char *my_strcpy(char *dest, const char *src);
void add(History *h, char *command);
void back(History *h);
void forward(History *h);
void print_all(History *h);
void cleanup(History *h);

#endif