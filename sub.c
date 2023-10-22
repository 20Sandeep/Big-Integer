#include <stdio.h>
#include <stdlib.h>
#include <string.h>


struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtBeginning(struct Node* head, int digit) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = digit;
    newNode->next = head;
    return newNode;
}

struct Node* subtractBigNumbers(struct Node* num1, struct Node* num2) {
    struct Node* result = NULL;
    int borrow = 0;

    while (num1) {
        int diff = num1->data - borrow;
        borrow = 0;

        if (num2) {
            diff -= num2->data;
            num2 = num2->next;
        }

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }

        result = insertAtBeginning(result, diff);
        num1 = num1->next;
    }

    while (num2) {
        int diff = num2->data - borrow;
        borrow = 0;

        if (diff < 0) {
            diff += 10;
            borrow = 1;
        }

        result = insertAtBeginning(result, diff);
        num2 = num2->next;
    }

    return result;
}


void displayList(struct Node* head) {
    struct Node* current = head;

    while (current) {
        printf("%d", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Node* num1 = NULL;
    struct Node* num2 = NULL;
    struct Node* result = NULL;
    char num1Str[100], num2Str[100];
    int choice;

    do {
        printf("Menu:\n");
        printf("1. Enter first big number\n");
        printf("2. Enter second big number\n");
        printf("3. Subtract numbers\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first big number: ");
                scanf("%s", num1Str);
                int len1 = strlen(num1Str);
                for (int i = 0; i < len1; i++) {
                    num1 = insertAtBeginning(num1, num1Str[i] - '0');
                }
                break;
            case 2:
                printf("Enter the second big number: ");
                scanf("%s", num2Str);
                int len2 = strlen(num2Str);
                for (int i = 0; i < len2; i++) {
                    num2 = insertAtBeginning(num2, num2Str[i] - '0');
                }
                break;
            case 3:
                result = subtractBigNumbers(num1, num2);
                printf("Difference: ");
                displayList(result);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    
    while (num1) {
        struct Node* temp = num1;
        num1 = num1->next;
        free(temp);
    }

    while (num2) {
        struct Node* temp = num2;
        num2 = num2->next;
        free(temp);
    }

    while (result) {
        struct Node* temp = result;
        result = result->next;
        free(temp);
    }

    return 0;
}
