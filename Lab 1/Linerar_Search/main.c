#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, found, arr[10], n, key;
    printf("Enter the number of elements:\n");
    scanf("%d", &n);
    printf("Enter the elements:\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter the element to be found:\n");
    scanf("%d", &key);

    for(i=0;i<n;i++){
        if(arr[i]==key){
            found=1;
            break;
        }
    }
    if(found=1){
        printf("Element found at position %d\n", i+1);
    }
    else
        printf("Element not found");

    return 0;
}
