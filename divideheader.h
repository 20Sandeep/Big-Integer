#ifndef BIG_INT_DIVIDE_H
#define BIG_INT_DIVIDE_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int x);
Node* readNumber();
double divideTwoLists(Node* l1, Node* l2);

#endif 