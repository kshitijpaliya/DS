#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the binary tree
struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to check if two trees are mirror images
int areMirror(struct TreeNode* root1, struct TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) return 1;

    if (root1 != NULL && root2 != NULL) {
        return (root1->data == root2->data) &&
               areMirror(root1->left, root2->right) &&
               areMirror(root1->right, root2->left);
    }

    return 0;
}

int main() {
    struct TreeNode* root1 = NULL;
    struct TreeNode* root2 = NULL;
    int data1, data2;
    char choice;

    printf("Enter elements for the first tree:\n");
    do {
        printf("Enter an element: ");
        scanf("%d", &data1);

        struct TreeNode* newNode = createNode(data1);

        if (root1 == NULL) {
            root1 = newNode;
        } else {
            struct TreeNode* current = root1;
            struct TreeNode* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data1 < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (data1 < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("\nEnter elements for the second tree:\n");
    do {
        printf("Enter an element: ");
        scanf("%d", &data2);

        struct TreeNode* newNode = createNode(data2);

        if (root2 == NULL) {
            root2 = newNode;
        } else {
            struct TreeNode* current = root2;
            struct TreeNode* parent = NULL;
            while (current != NULL) {
                parent = current;
                if (data2 < current->data)
                    current = current->left;
                else
                    current = current->right;
            }
            if (data2 < parent->data)
                parent->left = newNode;
            else
                parent->right = newNode;
        }

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    if (areMirror(root1, root2)) {
        printf("\nThe trees are mirror images.\n");
    } else {
        printf("\nThe trees are not mirror images.\n");
    }

    return 0;
}
