#include <stdio.h>
#include <stdlib.h>

int main()
{
int i, j, arr[10], n, key, low, mid, high;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be found:\n");
    scanf("%d", &key);

    low=0;
    high=n-1;
   do{
    mid=(low+high)/2;
        if(arr[mid]>key){
            high=mid-1;
        }
        else
        if(arr[mid]<key){
            low=mid+1;
        }
    }while(arr[mid]!=key && low<=high);

   if(arr[mid]=key){
        printf("Element found at position: %d", mid+1);
        }
   else
       printf("Element Not Found");
    return 0;
}
