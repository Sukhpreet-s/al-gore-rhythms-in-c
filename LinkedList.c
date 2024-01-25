#include <stdio.h>

struct Node {
    int value;
    struct Node *next;
};

// Returns a first node(head) in LL
struct Node createList(int value) {
    struct Node node;
    node.value = value;
    node.next = NULL;

    return node;
}

void addNodeAtIndex(struct Node head, int value, int index) {
    struct Node newNode;
    newNode.value = value;
    newNode.next = NULL; 
    
    struct Node node = head;
    int i = 0;
    // Traverse either till the last element or one before the given index.
    while(i < index-1 && node.next != NULL) {
        node = *(node.next);
        i++;
    }

    // Looped through LL to reach node at i-1 to append.
    // NOTE: if the index is larger than the list's length, then new node is appended at the last.
    newNode.next = node.next;
    node.next = &newNode;
}

void printList(struct Node head) {
    struct Node node = head;
    while (node.next != NULL) {
        printf("Value: %d, Addr: %p\n", node.value, node.next);
        node = *(node.next);
    }

    // Print last element
    printf("Value: %d, Addr: %p\n", node.value, node.next);
}

// Node 1 (value, next:(Node 2)) -> Node 2 (value, next:(Node 3)) -> Node 3 (value, next:())

int main(){
    printf("Linked list says hello!\n");

    struct Node head = createList(11);
    addNodeAtIndex(head, 12, 1);
    addNodeAtIndex(head, 13, 2);
    addNodeAtIndex(head, 14, 3);
    // printf("Next addr: %p", head.next);
    printList(head);
}