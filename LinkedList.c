#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int value;
    struct node *next;
} Node;

Node* createNewNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    return newNode;
}

/**
head -> Doulbe pointer is required in order to set head pointer in main func to point to the new node if NULL.
*/
void appendNode(Node** head, int value) {
    Node* newNode = createNewNode(value);

    // set the head for caller of this function, i.e. main func.
    if (*head == NULL) {
        *head = newNode;
        return;
    }

    // Iterate over the LL to go to last element.
    Node* temp = *head;
    while(temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void printList(Node* head) {
    while(head != NULL) {
        printf("Value: %d\n", head->value);
        head = head->next;
    }
}

int main(){
    Node* head = NULL;

    appendNode(&head, 11);
    appendNode(&head, 12);
    appendNode(&head, 13);

    printList(head);
}