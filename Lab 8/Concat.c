#include<stdio.h>

typedef struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    newNode->prev = NULL;
    return newNode;
}

void insert(Node* header, int data)
{
    Node* newNode = createNode(data);
    Node* current = header;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
    newNode->prev = current;
}

void display(Node* header)
{
    if (header->next == NULL)
    {
        printf("Doubly linked list is empty.\n");
        return;
    }
    Node* current = header->next;
    printf("Doubly linked list elements: ");
    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    Node* header1 = createNode(-1);
    Node* header2 = createNode(-1);
    int choice, data;
    printf("enter first linked list");
    int ch;
    do
    {

        scanf("%d", &data);
        insert(header1, data);

        printf("continue? enter 1\n");
        scanf("%d",&ch);
    }
    while(ch==1);

    printf("enter second linked list");
    do
    {

        scanf("%d", &data);
        insert(header2, data);

        printf("continue? enter 1\n");
        scanf("%d",&ch);
    }
    while(ch==1);

    Node* current = header1;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next=header2->next;
    (
        header2->next)->prev=current;

    printf("displaying concatenated linked list");
    display(header1);
    return 0;
}
