#include<stdio.h>
#include<stdlib.h>

struct Node {
    int data;
    struct Node*next;
};

struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}

void InsertBefore(struct Node** head, int data, int befdata)
{
    struct Node* newNode = createNode(data);
    if (*head==NULL)
    {
        printf("The list is empty\n");
        return;
    }

    struct Node* temp= *head;
    struct Node* prev = NULL;
    while(temp != NULL && temp->data != befdata)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Element %d not found in the list\n", befdata);
        free(newNode);
        return;
    }

    if(prev==NULL)
    {
        newNode->next=*head;
        *head=newNode;
    }

    else
    {
        prev->next=newNode;
        newNode->next=temp;
    }
}

void InsertAfter(struct Node* head, int data, int afterdata)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = head;

    while(temp!=NULL && temp->data!=afterdata)
    {
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Element not found in the list\n", afterdata);
        free(newNode);
        return;
    }

    newNode->next=temp->next;
    temp->next=newNode;
}

void DeleteElement(struct Node** head, int data)
{
    if(*head==NULL)
    {
        printf("List is empty\n");
        return;
    }

    struct Node* temp = *head;
    struct Node* prev = NULL;

    while(temp!=NULL && temp->data != data)
    {
        prev=temp;
        temp=temp->next;
    }

    if(temp==NULL)
    {
        printf("Element %d not found in the list\n", data);
        return;
    }

    if(prev==NULL)
    {
        *head=temp->next;
    }

    else
    {
        prev->next=temp->next;
    }
    free(temp);
}

void Traverse(struct Node* head)
{
    printf("List: ");
    while(head!=NULL)
    {
        printf("%d", head->data);
        head=head->next;
    }
    printf("\n");
}

void Reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next = NULL;

    while(current != NULL)
    {
        next=current->next;
        current->next = prev;
        prev=current;
        current=next;
    }
    *head=prev;
}

void DeleteAlternate(struct Node** head)
{
    if(*head==NULL)
    {
        printf("List is empty");
        return;
    }

    struct Node* current = *head;
    struct Node* next;

    while(current != NULL && current->next!=NULL)
    {
        next=current->next;
        current->next=next->next;
        free(next);
        current=current->next;
    }
}

void InsertSorted(struct Node** head, int data)
{
    struct Node* newNode = createNode(data);

    if(*head == NULL || data<= (*head)->data)
    {
        newNode->next=*head;
        *head=newNode;
        return;
    }

    struct Node* temp = *head;
    while(temp->next!=NULL && temp->next->data<data)
    {
        temp=temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to insert a new element at the end of the linked list
 struct Node* insert(Node* head, int data) {
 struct Node* newNode = createNode(data);
 if (head == NULL) {
 head = newNode;
 } else {
 Node* current = head;
 while (current->next != NULL) {
 current = current->next;
 }
 current->next = newNode;
 }
 return head;
}

int main() {
    struct Node* head = NULL;
    int choice, data, beforeData, afterData;

    do {
        printf("\nMenu:\n");
        printf("1. Insert before element\n");
        printf("2. Insert after element\n");
        printf("3. Delete element\n");
        printf("4. Traverse list\n");
        printf("5. Reverse list\n");
        printf("6. Sort list\n");
        printf("7. Delete every alternate node\n");
        printf("8. Insert in sorted list\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter element before which to insert: ");
                scanf("%d", &beforeData);
                InsertBefore(&head, data, beforeData);
                break;
            case 2:
                printf("Enter element to insert: ");
                scanf("%d", &data);
                printf("Enter element after which to insert: ");
                scanf("%d", &afterData);
                InsertAfter(head, data, afterData);
                break;
            case 3:
                printf("Enter element to delete: ");
                scanf("%d", &data);
                DeleteElement(&head, data);
                break;
            case 4:
                Traverse(head);
                break;
            case 5:
                Reverse(&head);
                printf("List reversed.\n");
                break;
            case 6:
                // (Optional) Add code for sorting the list
                break;
            case 7:
                DeleteAlternate(&head);
                printf("Every alternate node deleted.\n");
                break;
            case 8:
                printf("Enter element to insert in sorted list: ");
                scanf("%d", &data);
                InsertSorted(&head, data);
                break;
            case 0:
                // Exit
                break;
            case 9:
                printf("Enter the element to insert: ");
 scanf("%d", &data);
 head = insert(head, data);
 break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 0);

    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
