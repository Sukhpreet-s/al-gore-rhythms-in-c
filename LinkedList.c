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

/**
Insert a given value at a given index.
*/
void insertAt(Node** head, int value, int index) {
    Node* newNode = NULL;
    // Base cases
    // 1. Index out of bound 
    // if greater than length: Handled while iterating because we don't have a track of length.
    // if less than 0
    if(index<0) {
        printf("Index out of bound!\n");
        return;
    }

    // 2. List is empty 
    if(*head == NULL) {
        newNode = createNewNode(value);
        *head = newNode;
        return;
    }

    // 3. If inserting at index 0
    if(index == 0) {
        newNode = createNewNode(value);
        newNode->next = *head;
        *head = newNode;
        return;
    }

    // Basic implementation if index>=1.
    // So if i = 0, we are insertig at index 1.  
    //      1. Using < (!<=) since at the end of every loop, head will point to i+1 node 
    //      2. Using (index-1) since after done looping, we need to be at node that is at (index-1)
    Node* curr = *head;
    int i = 0;
    while (i<index-1) {
        // If node before index is null, we cannot set a node at index.
        if(curr->next == NULL) {
            printf("Index out of bound!\n");
            return;
        }

        curr = curr->next;
        i++;
    }

    // Head is pointing to index-1 at this point
    newNode = createNewNode(value);

    newNode->next = curr->next;
    curr->next = newNode;
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
    appendNode(&head, 13);
    appendNode(&head, 14);

    printList(head);
    printf("----------\n");

    printf("Adding at index 1\n");
    insertAt(&head, 12, 1);
    printList(head);
    printf("----------\n");

    printf("Adding at index 0\n");
    insertAt(&head, 10, 0);
    printList(head);
    printf("----------\n");

    printf("Adding at last index\n");
    insertAt(&head, 5, 5);
    printList(head);
    printf("----------\n");

    // Breaking tests
    printf("Adding at index -1\n");
    insertAt(&head, 9, -1);
    printList(head);
    printf("----------\n");
    
    printf("Adding at index out of bound (10)\n");
    insertAt(&head, 99, 10);
    printList(head);
    printf("----------\n");

}