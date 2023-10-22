#ifndef BIG_INT_MULTIPLY_H
#define BIG_INT_MULTIPLY_H

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int x);
Node* readNumber();
long long multiplyTwoLists(Node* l1, Node* l2);

#endif 
