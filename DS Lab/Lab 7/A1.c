#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Recursive function to create a linked list
struct Node* createLinkedListRecursively() {
    int data;
    struct Node* newNode;

    printf("Enter data (or -1 to end): ");
    scanf("%d", &data);

    if (data == -1) {
        return NULL;
    }

    newNode = createNode(data);
    newNode->next = createLinkedListRecursively();

    return newNode;
}

// Recursive function to traverse a linked list
void traverseLinkedListRecursively(struct Node* head) {
    if (head == NULL) {
        return;
    }

    printf("%d -> ", head->data);
    traverseLinkedListRecursively(head->next);
}

int main() {
    struct Node* head = createLinkedListRecursively();

    if (head == NULL) {
        printf("The linked list is empty.\n");
    } else {
        printf("Linked List: ");
        traverseLinkedListRecursively(head);
        printf("NULL\n");
    }

    // Remember to free allocated memory when you're done with the list

    return 0;
}
