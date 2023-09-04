#include<stdio.h>

void selectionSort(int arr[],int n)
{
    int min,pos;

    for(int i=0;i<n-1;i++)
    {
        int min =arr[i];
        pos=i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                pos=j;
            }
        }

        arr[pos]=arr[i];
        arr[i]=min;


    }
}

int main()
{

    int arr[10],n,ele;
    printf("size:");
    scanf("%d",&n);



    printf("enter arr:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }

    selectionSort(arr,n);
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
//    int i, j, arr[10], n, pos, temp;
//    printf("Enter the number of elements:\n");
//    scanf("%d", &n);
//    printf("Enter the elements:\n");
//    for(i=0;i<n;i++){
//        scanf("%d", &arr[i]);
//    }
//
//    for(i=0;i<n-1;i++){
//            pos=i;
//        for(j=i+1;j<n;j++)
//        if(arr[pos]>arr[j]){
//            pos=j;
//        if(pos!=i){
//            temp=arr[i];
//            arr[i]=arr[pos];
//            arr[pos]=temp;
//        }
//        }
//    }
//    printf("The elements are:\n");
//    for(i=0;i<n;i++){
//        printf("%d\t", arr[i]);
//    }
//    return 0;
//}
