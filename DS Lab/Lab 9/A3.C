#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the circular doubly linked list
struct Node {
    int machineNumber;
    int bookingTime;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int machineNumber, int bookingTime) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->machineNumber = machineNumber;
    newNode->bookingTime = bookingTime;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a node into the circular doubly linked list
void insertNode(struct Node** head, int machineNumber, int bookingTime) {
    struct Node* newNode = createNode(machineNumber, bookingTime);

    if (*head == NULL) {
        *head = newNode;
        (*head)->next = newNode;
        (*head)->prev = newNode;
    } else {
        struct Node* tail = (*head)->prev;
        tail->next = newNode;
        newNode->prev = tail;
        newNode->next = *head;
        (*head)->prev = newNode;
    }
}

// Function to simulate renting a washing machine
void rentWashingMachine(struct Node** head) {
    if (*head == NULL) {
        printf("No washing machines available.\n");
        return;
    }

    struct Node* rentedMachine = *head;
    printf("Rented Machine Number: %d\n", rentedMachine->machineNumber);

    if (rentedMachine->next == rentedMachine) {
        free(rentedMachine);
        *head = NULL;
    } else {
        rentedMachine->prev->next = rentedMachine->next;
        rentedMachine->next->prev = rentedMachine->prev;
        *head = rentedMachine->next;
        free(rentedMachine);
    }
}

// Function to display the status of washing machines
void displayStatus(struct Node* head) {
    if (head == NULL) {
        printf("No washing machines available.\n");
        return;
    }

    struct Node* current = head;

    do {
        printf("Machine Number: %d, Booking Time: %d\n", current->machineNumber, current->bookingTime);
        current = current->next;
    } while (current != head);
}

int main() {
    struct Node* washingMachines = NULL;
    int machineCount, bookingTime, i;

    printf("Enter the number of washing machines: ");
    scanf("%d", &machineCount);

    for (i = 1; i <= machineCount; i++) {
        insertNode(&washingMachines, i, 0);
    }

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Rent a washing machine\n");
        printf("2. Display washing machine status\n");
        printf("3. Quit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter booking time (in minutes): ");
                scanf("%d", &bookingTime);
                insertNode(&washingMachines, 0, bookingTime);
                rentWashingMachine(&washingMachines);
                break;
            case 2:
                displayStatus(washingMachines);
                break;
            case 3:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }

    } while (choice != 3);

    // Free allocated memory
    if (washingMachines != NULL) {
        struct Node* current = washingMachines;
        do {
            struct Node* next = current->next;
            free(current);
            current = next;
        } while (current != washingMachines);
    }

    return 0;
}
