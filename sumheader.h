#ifndef BIG_INT_ADD_H
#define BIG_INT_ADD_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int digit);
struct Node* addBigNumbers(struct Node* num1, struct Node* num2);
void displayList(struct Node* head);

#endif 
