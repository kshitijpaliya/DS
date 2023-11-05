#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

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

void initStack(struct Stack* stack) {
    stack->top = NULL;
}

void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(struct Stack* stack) {
    if (stack->top == NULL) {
        printf("Error: Stack is empty\n");
        return -1;
    }

    int data = stack->top->data;
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    free(temp);
    return data;
}

int isEmptyStack(struct Stack* stack) {
    return (stack->top == NULL);
}

void initQueue(struct Queue* queue) {
    queue->front = queue->rear = NULL;
}

void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);

    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }

    queue->rear->next = newNode;
    queue->rear = newNode;
}

int dequeue(struct Queue* queue) {
    if (queue->front == NULL) {
        printf("Error: Queue is empty\n");
        return -1;
    }

    int data = queue->front->data;
    struct Node* temp = queue->front;

    if (queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }

    free(temp);
    return data;
}

int isEmptyQueue(struct Queue* queue) {
    return (queue->front == NULL);
}

int main() {
    struct Stack stack;
    struct Queue queue;

    initStack(&stack);
    initQueue(&queue);

    int choice, data;

    do {
        printf("\nMenu:\n");
        printf("1. Push onto Stack\n");
        printf("2. Pop from Stack\n");
        printf("3. Enqueue into Queue\n");
        printf("4. Dequeue from Queue\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to push onto stack: ");
                scanf("%d", &data);
                push(&stack, data);
                break;

            case 2:
                data = pop(&stack);
                if (data != -1) {
                    printf("Popped from stack: %d\n", data);
                }
                break;

            case 3:
                printf("Enter data to enqueue into queue: ");
                scanf("%d", &data);
                enqueue(&queue, data);
                break;

            case 4:
                data = dequeue(&queue);
                if (data != -1) {
                    printf("Dequeued from queue: %d\n", data);
                }
                break;

            case 0:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}
