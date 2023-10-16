#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
    struct Node* prev;
};

struct Node* head = NULL;


void insertRear(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL)
    {
        newNode->prev = NULL;
        head = newNode;
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
}

void deleteRear()
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    if (temp->prev != NULL)
    {
        temp->prev->next = NULL;
        free(temp);
    }
    else
    {
        free(temp);
        head = NULL;
    }
}

void insertPosition(int data, int position)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1)
    {
        newNode->next = head;
        newNode->prev = NULL;
        if (head != NULL)
        {
            head->prev = newNode;
        }
        head = newNode;
        return;
    }

    struct Node* temp = head;
    for (int i = 1; i < position - 1; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void deletePosition(int position)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = head;
    if (position == 1)
    {
        head = head->next;
        free(temp);
        if (head != NULL)
        {
            head->prev = NULL;
        }
        return;
    }

    for (int i = 1; i < position; i++)
    {
        if (temp == NULL)
        {
            printf("Invalid position.\n");
            return;
        }
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Invalid position.\n");
        return;
    }

    temp->prev->next = temp->next;
    if (temp->next != NULL)
    {
        temp->next->prev = temp->prev;
    }
    free(temp);
}

void insertAfter(int data, int afterData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    while (temp != NULL && temp->data != afterData)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found.\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL)
    {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
}

void insertBefore(int data, int beforeData)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    struct Node* temp = head;
    while (temp != NULL && temp->data != beforeData)
    {
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("Element not found.\n");
        free(newNode);
        return;
    }

    newNode->prev = temp->prev;
    newNode->next = temp;
    if (temp->prev != NULL)
    {
        temp->prev->next = newNode;
    }
    temp->prev = newNode;

    if (temp == head)
    {
        head = newNode;
    }
}

void traverse()
{
    struct Node* temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reverse()
{
    struct Node* temp = NULL;
    struct Node* current = head;

    while (current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL)
    {
        head = temp->prev;
    }
}

void display(struct Node* head)
{
    if(head->next=NULL)
    {
        printf("List is Empty");
        return;
    }

    struct Node*current=head->next;
    printf("Doubly LL: ");
    {
        printf("%d", current->data);
        current=current->next;
    }
    printf("\n");
}


int main()
{
    int choice, data, position, afterData, beforeData;
//    struct Node* head = createNode(-1);
    while (1)
    {
        printf("\n1. Insert at rear\n2. Delete from rear\n3. Insert at position\n4. Delete from position\n5. Insert after element\n6. Insert before element\n7. Traverse\n8. Reverse\n9. Display\n10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            insertRear(data);
            break;
        case 2:
            deleteRear();
            break;
        case 3:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter position: ");
            scanf("%d", &position);
            insertPosition(data, position);
            break;
        case 4:
            printf("Enter position to delete: ");
            scanf("%d", &position);
            deletePosition(position);
            break;
        case 5:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter data after which to insert: ");
            scanf("%d", &afterData);
            insertAfter(data, afterData);
            break;
        case 6:
            printf("Enter data to insert: ");
            scanf("%d", &data);
            printf("Enter data before which to insert: ");
            scanf("%d", &beforeData);
            insertBefore(data, beforeData);
            break;
        case 7:
            printf("Linked List: ");
            traverse();
            break;
        case 8:
            reverse();
            printf("List is reversed.\n");
            break;
        case 9:
            display(head);
            break;
        case 10:
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }
    return 0;
}
