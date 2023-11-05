#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the doubly linked list
struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node at the end of a doubly linked list
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

// Function to display a doubly linked list
void displayList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

// Function to find the union of two doubly linked lists
void findUnion(struct Node* list1, struct Node* list2) {
    struct Node* unionList = NULL;

    while (list1 != NULL) {
        insertEnd(&unionList, list1->data);
        list1 = list1->next;
    }

    while (list2 != NULL) {
        if (!search(unionList, list2->data)) {
            insertEnd(&unionList, list2->data);
        }
        list2 = list2->next;
    }

    printf("Union of the lists: ");
    displayList(unionList);
}

// Function to find the intersection of two doubly linked lists
void findIntersection(struct Node* list1, struct Node* list2) {
    struct Node* intersectionList = NULL;

    while (list1 != NULL) {
        if (search(list2, list1->data)) {
            insertEnd(&intersectionList, list1->data);
        }
        list1 = list1->next;
    }

    printf("Intersection of the lists: ");
    displayList(intersectionList);
}

// Function to search for an element in a doubly linked list
int search(struct Node* head, int key) {
    while (head != NULL) {
        if (head->data == key) {
            return 1;
        }
        head = head->next;
    }
    return 0;
}

int main() {
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    int data, choice;

    // Taking user input for the first doubly linked list
    printf("Enter elements for the first list (enter -1 to stop):\n");
    do {
        scanf("%d", &data);
        if (data != -1) {
            insertEnd(&list1, data);
        }
    } while (data != -1);

    // Taking user input for the second doubly linked list
    printf("Enter elements for the second list (enter -1 to stop):\n");
    do {
        scanf("%d", &data);
        if (data != -1) {
            insertEnd(&list2, data);
        }
    } while (data != -1);

    printf("Lists created successfully!\n");

    do {
        printf("\nMenu:\n");
        printf("1. Find Union of Lists\n");
        printf("2. Find Intersection of Lists\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                findUnion(list1, list2);
                break;
            case 2:
                findIntersection(list1, list2);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    // Free allocated memory
    while (list1 != NULL) {
        struct Node* temp = list1;
        list1 = list1->next;
        free(temp);
    }

    while (list2 != NULL) {
        struct Node* temp = list2;
        list2 = list2->next;
        free(temp);
    }

    return 0;
}
