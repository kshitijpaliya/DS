#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, a[10][10], b[10][10], c[10][10], n;
    printf("Enter the order of matrix A and B:\n");
    scanf("%d", &n);
    printf("Enter the elements of A:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of B:\n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        scanf("%d", &b[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        if(a[i][j]>b[i][j])
            c[i][j]=a[i][j];
        else
        if(a[i][j]<b[i][j]){
            c[i][j]=b[i][j];
        }
        }
    }
 printf("Elements of C are:\n");
for(i=0;i<n;i++){
        for(j=0;j<n;j++){
        printf("%d\t", c[i][j]);
        }
    }
return 0;
}
