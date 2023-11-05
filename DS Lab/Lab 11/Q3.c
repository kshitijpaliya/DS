#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode *left;
    struct TreeNode *right;
};

// Function to create a new node
struct TreeNode* createNode(int data) {
    struct TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    newNode->data = data;
    newNode->left = newNode->right = NULL;
    return newNode;
}

// Function to insert a node into the binary search tree
struct TreeNode* insertNode(struct TreeNode* root, int data) {
    if (root == NULL) {
        return createNode(data);
    }

    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }

    return root;
}

// Function to search for an element in the binary search tree
struct TreeNode* searchElement(struct TreeNode* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }

    if (key < root->data) {
        return searchElement(root->left, key);
    } else {
        return searchElement(root->right, key);
    }
}

int main() {
    struct TreeNode* root = NULL;
    int data;
    char choice;

    do {
        printf("Enter an element to insert into the BST: ");
        scanf("%d", &data);
        root = insertNode(root, data);

        printf("Do you want to insert another element? (y/n): ");
        scanf(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    int elementToSearch;
    printf("Enter an element to search for in the BST: ");
    scanf("%d", &elementToSearch);

    struct TreeNode* result = searchElement(root, elementToSearch);

    if (result != NULL) {
        printf("%d found in the BST.\n", elementToSearch);
    } else {
        printf("%d not found in the BST.\n", elementToSearch);
    }

    return 0;
}
