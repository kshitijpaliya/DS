#include<stdlib.h>

typedef struct node
{
    int data;
    struct node * next;
}node;
node * first = NULL;

void disp(void)
{
    node * curr;
    if(first == NULL)
    {
        printf("List is empty\n");
    }
    else
    {
        for(curr = first; curr != NULL; curr = curr -> next)
        {
            printf("%d\t", curr -> data);
        }
        printf("\n");
    }
}

void insert_last(int ele)
{
    node * temp = (node *) malloc (sizeof(node));
    temp -> next = NULL;
    temp -> data = ele;

    node * curr;
    if(first == NULL)
    {
        first = temp;
    }

    else
    {
        for(curr = first; curr -> next != NULL; curr = curr -> next);
        curr -> next = temp;
    }
}

void insert_before_ele(int ele, int bdata)
{
    node * temp = (node *) malloc (sizeof(node));
    temp -> data = ele;
    node * prev;
    node * curr;
    int flag = 0;

    for(curr = first; curr != NULL; prev = curr, curr = curr -> next)
    {
        if(curr -> data == bdata)
        {
            flag = 1;
            temp -> next = prev -> next;
            prev -> next = temp;
            printf("Element has been inserted\n");
        }
    }

    if(flag == 0)
    {
        printf("Element not found\n");
    }

}

void insert_after_ele(int ele, int adata)
{
    node * temp = (node *) malloc(sizeof(node));
    node * curr;
    int flag = 0;

    for(curr = first; curr != NULL; curr = curr -> next)
    {
        if(curr -> data == adata)
        {
            flag = 1;
            temp -> data = ele;
            temp -> next = curr -> next;
            curr -> next = temp;
            printf("Node has been inserted\n");
            break;
        }
    }

    if(flag == 0)
    {
        printf("Entered element not found\n");
    }
}

void del(int ele)
{
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        node * curr;
        node * prev = first;
        node * temp;
        int flag = 0;

        for(curr = first; curr != NULL; prev = curr, curr = curr -> next)
        {
            if(curr -> data == ele)
            {
                temp = curr;
                flag = 1;
                prev -> next = curr -> next;
                free(temp);
                break;
            }
        }

        if(flag == 0)
        {
            printf("Node not found\n");
        }
    }
}

void traverse(int ele)
{
    node * curr;
    int count = 0, flag = 0;
    for(curr = first; curr != NULL; curr = curr -> next)
    {
        count++;
        if(curr -> data == ele)
        {
            flag = 1;
            printf("Element found at position: %d\n", count);
            break;
        }
    }

    if(flag == 0)
    {
        printf("Element not found\n");
    }
}
void rev(void)
{
    node * temp;
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        node * curr = first -> next;
        first -> next = NULL;

        while(curr != NULL)
        {
            temp = curr;
            curr = curr -> next;
            temp -> next = first;
            first = temp;
        }
    }
}

node * swap(node * a, node * b)
{
    node * temp = b -> next;
    b -> next = a;
    a -> next = temp;
    return b;
}

void sort(void)
{
    //write code
}

void del_alternate()
{
    if(first == NULL)
    {
        printf("List is empty\n");
    }

    else
    {
        int i = 0;
        node * curr = first;
        node * prev = first;
        node * temp;
       while(curr != NULL)
       {
           if(i % 2 == 0)
           {
               temp = curr;
               if(i == 0)
               {
                   first = curr -> next;
                   curr = curr -> next;
               }

               else
               {
                   prev -> next = curr -> next;
                   curr = curr -> next;
               }

               i++;
               free(temp);
           }

           else
           {
               i++;
               prev = curr;
               curr = curr -> next;
           }

       }
    }
}

void insert_sort(int ele)
{
    node * curr;
    node * prev;

    for(curr = first; curr != NULL; prev = curr, curr = curr -> next)
    {
        if(curr -> data > ele)
        {
            insert_before_ele(ele, curr -> data);
            break;
        }
    }
}


int main(void)
{
    int opt, key, ele;
    do
    {
        printf("Enter 1 for inserting at the end\nEnter 2 for inserting before an element\nEnter 3 to insert after an element\nEnter 4 to delete an element\nEnter 5 to traverse the list and find an element\nEnter 6 to reverse the list\nEnter 7 to sort the list\nEnter 8 to delete alternate nodes in the list\nEnter 9 to insert an element in a sorted list maintaining the order\nEnter 10 to exit the program\n");
        printf("Enter option: ");
        scanf("%d", &opt);
        {
            switch(opt)
            {
            case 1:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                insert_last(ele);
                disp();
                break;

            case 2:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);

                printf("Enter element before which the given element has to be inserted: ");
                scanf("%d", &key);

                insert_before_ele(ele, key);
                disp();
                break;

            case 3:
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);

                printf("Enter element after which the given element has to be inserted: ");
                scanf("%d", &key);

                insert_after_ele(ele, key);
                disp();
                break;

            case 4:
                printf("Enter element to be deleted: ");
                scanf("%d", &ele);
                del(ele);
                disp();
                break;

            case 5:
                printf("Enter element to be found: ");
                scanf("%d", &ele);
                traverse(ele);
                break;

            case 6:
                rev();
                disp();
                break;

            case 7:
                sort();
                disp();
                break;

            case 8:
                del_alternate();
                disp();
                break;

            case 9:
                sort();
                printf("Enter element to be inserted: ");
                scanf("%d", &ele);
                insert_sort(ele);
                disp();
                break;
            }
        }
    }while(opt != 10);
}

