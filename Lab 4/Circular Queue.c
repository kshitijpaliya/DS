#include<stdio.h>
#define SIZE 5

int queue[SIZE];
int rear = -1;
int front =-1;

void enqueue(int queue[],int ele)
{
    if((rear+1) % SIZE == front)
    {
        printf("Queue full");
        return;
    }
    else if(front == -1)
    {
        front = rear = 0;
        //printf("%d",front);
        queue[front] = ele;
    }
    else
    {
        rear = (rear + 1) % SIZE;
        queue[rear] = ele;
    }
}

void dequeue(int queue[])
{
    if( front == -1)
    {
        printf("Queue empty");
        return;
    }
    else if(front == rear)
    {
        front = rear = -1;
    }
    else
    {
        front++;
    }
}

void display(int queue[])
{
    //printf("dis: %d , rear:%d\n",front,rear);
    if(front == -1)
    {
        printf("Queue empty");
        //printf("%d",front);
        return;
    }
    if(front == rear)
    {
        printf("%d",queue[front]);
       // printf("Enter");
        return;
    }

    if(front<rear)
    {
        for(int i=front;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }

    }
    else
    {
        for(int i=front;i<SIZE;i++)
        {
            printf("%d ",queue[i]);
        }

        for(int i=0;i<=rear;i++)
        {
            printf("%d ",queue[i]);
        }
    }


}
int main()
{

    int ch,ele;

    while(1)
    {
        printf("\n1. Insert an element\n");
        printf("2. Delete an element\n");
        printf("3. Display the queue\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &ch);
        printf("\n");


        switch(ch)
        {
        case 1:
            printf("Element to insert:");
            scanf("%d",&ele);
            enqueue(&queue,ele);
            break;

        case 2:
            dequeue(&queue);
            break;

        case 3:
            display(&queue);
            break;
        case 4:
            return;
        }

    }
}




//#include<stdio.h>
//#define MAX 5
//
//int queue[MAX];
//int front=-1, rear=-1;
//
//int checkEmpty()
//{
//    if(rear==-1)
//    {
//        return 1;
//    }
//    return 0;
//}
//
//int checkFull()
//{
//    if((rear+1) % MAX == front)
//    {
//        return 1;
//    }
//    return 0;
//}
//
//void enqueue(int queue[], int n)
//{
//    if(checkEmpty())
//    {
//        printf("Queue is Empty");
//        rear=front=0;
//        queue[front]=n;
//    }
//    else if(checkFull())
//    {
//        printf("Queue is Full");
//    }
//    else
//    {
//        rear=(rear+1)%MAX;
//        queue[rear]=n;
//        printf("%d was enqueued.", n);
//    }
//}
//
//void dequeue(int queue[])
//{
//    int x;
//    if(checkEmpty())
//    {
//        printf("Queue is Empty");
//    }
//
//    else
//    {
//        x=queue[front];
//        if(front==rear)
//        {
//            front=rear-1;
//        }
//        else
//        {
//            //front=(front+1)%MAX;
//            front++;
//        }
//        printf ("%d was dequeued\n", x);
//    }
//}
//
//void display()
//{
//  int i;
//  if (checkEmpty())
//    printf ("Nothing to dequeue\n");
//
//  if(front == rear)
//    {
//        printf("%d",queue[front]);
//        return;
//    }
//
//
//      if(front<rear)
//      for(i=front;i<=rear;i++)
//      {
//          printf("%d\t", queue[i]);
//      }
//      else
//      {
//      for(i=front;i<MAX;i++)
//      {
//          printf("%d\t", queue[i]);
//      }
//      for(i=0;i<rear;i++)
//      {
//          printf("%d\t", queue[i]);
//      }
//      }
//    }
//
//
//int main ()
//{
//     int choice, item;
//     while (1)
//    {
//     printf("\n1. Insert an element\n");
//     printf("2. Delete an element\n");
//     printf("3. Display the queue\n");
//     printf("4. Exit\n");
//     printf("Enter your choice: ");
//     scanf("%d", &choice);
//
//     switch (choice)
//         {
//         case 1:
//            printf("Enter the element to insert: ");
//            scanf("%d", &item);
//            enqueue(&queue, item);
//            break;
//
//         case 2:
//         dequeue(&queue);
//         break;
//
//         case 3:
//         display(&queue);
//         break;
//
//         case 4:
//         printf("Exiting the program.\n");
//         return 0;
//
//         default:
//         printf("Invalid choice! Please try again.\n");
//        }
//    }
//    return 0;
//}
