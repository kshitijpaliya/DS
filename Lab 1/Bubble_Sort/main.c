#include<stdio.h>

void bubbleSort(int arr[],int n)
{
    for (int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                int temp= arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
}

int main()
{

    int arr[10],n,ele;
    printf("size:");
    scanf("%d",&n);

    int s=0,e=n-1,mid;

    printf("enter arr:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
    {
        printf("%d ",arr[i]);
    }
}

//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//    int i, j, arr[10], n, temp;
//    printf("Enter the number of elements:\n");
//    scanf("%d", &n);
//    printf("Enter the elements:\n");
//    for(i=0;i<n;i++){
//        scanf("%d", &arr[i]);
//    }
//
//    for(i=0;i<n-1;i++){
//        for(j=0;j<n-i-1;j++)
//        if(arr[j]>arr[j+1]){
//            temp=arr[j];
//            arr[j]=arr[j+1];
//            arr[j+1]=temp;
//        }
//    }
//    printf("The elements are:\n");
//    for(i=0;i<n;i++){
//        printf("%d\t", arr[i]);
//    }
//    return 0;
//}
