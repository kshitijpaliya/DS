#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary search tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Define a structure for a node in the queue used for level order traversal
struct QueueNode {
    struct TreeNode* data;
    struct QueueNode* next;
};

// Define a structure for the queue
struct Queue {
    struct QueueNode* front;
    struct QueueNode* rear;
};

// Function to create a new node for the binary search tree
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to create a new node for the queue
struct QueueNode* createQueueNode(struct TreeNode* data) {
    struct QueueNode* newNode = (struct QueueNode*)malloc(sizeof(struct QueueNode));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new queue
struct Queue* createQueue() {
    struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}

// Function to enqueue a node in the queue
void enqueue(struct Queue* queue, struct TreeNode* data) {
    struct QueueNode* newNode = createQueueNode(data);
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}

// Function to dequeue a node from the queue
struct TreeNode* dequeue(struct Queue* queue) {
    if (queue->front == NULL)
        return NULL;

    struct QueueNode* temp = queue->front;
    struct TreeNode* data = temp->data;
    queue->front = queue->front->next;

    if (queue->front == NULL)
        queue->rear = NULL;

    free(temp);
    return data;
}

// Function to perform level order traversal
void levelOrderTraversal(struct TreeNode* root) {
    if (root == NULL)
        return;

    struct Queue* queue = createQueue();
    enqueue(queue, root);

    while (queue->front != NULL) {
        struct TreeNode* node = dequeue(queue);
        printf("%d ", node->data);

        if (node->left != NULL)
            enqueue(queue, node->left);

        if (node->right != NULL)
            enqueue(queue, node->right);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int data;
    char choice;

    do {
        printf("Enter an element to insert into the BST: ");
        scanf("%d", &data);
        struct TreeNode* newNode = createNode(data);

        if (root == NULL) {
            root = newNode;
        } else {
            struct TreeNode* current = root;
            struct TreeNode* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (data < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Level Order Traversal: ");
    levelOrderTraversal(root);
    printf("\n");

    return 0;
}
