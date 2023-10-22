#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

typedef struct Node Node;

Node* createNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

Node* readNumber() {
    char buffer[100];
    printf("Enter a number as a linked list: ");
    fgets(buffer, sizeof(buffer), stdin);

    Node* head = NULL;
    for (int i = 0; buffer[i] != '\0'; i++) {
        if (buffer[i] >= '0' && buffer[i] <= '9') {
            int digit = buffer[i] - '0';
            Node* newNode = createNode(digit);
            newNode->next = head;
            head = newNode;
        }
    }
    return head;
}

long long multiplyTwoLists(Node* l1, Node* l2) {
    long long num1 = 0, num2 = 0;

    Node* p1 = l1;
    Node* p2 = l2;

    while (p1 != NULL) {
        num1 = (num1 * 10 + p1->data);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        num2 = (num2 * 10 + p2->data);
        p2 = p2->next;
    }

    return num1 * num2;
}

int main() {
    int choice;
    Node* l1 = NULL;
    Node* l2 = NULL;
    long long result;

    while (1) {
        printf("Menu:\n");
        printf("1. Input Number 1\n");
        printf("2. Input Number 2\n");
        printf("3. Multiply\n");
        printf("4. Display Result\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); 

        switch (choice) {
            case 1:
                l1 = readNumber();
                break;
            case 2:
                l2 = readNumber();
                break;
            case 3:
                if (l1 != NULL && l2 != NULL) {
                    result = multiplyTwoLists(l1, l2);
                    printf("Multiplication done.\n");
                } else {
                    printf("Input both numbers first.\n");
                }
                break;
            case 4:
                if (l1 != NULL && l2 != NULL) {
                    printf("Result: %lld\n", result);
                } else {
                    printf("Please input and multiply numbers first.\n");
                }
                break;
            case 5:
                printf("Exiting the program.\n");
                exit(0);
            default:
                printf("Invalid choice. \n");
        }
    }

    return 0;
}
