#include <stdio.h>
#include <stdlib.h>

int main()
{

    int i, j, a[10][10], b[10][10], c[10][10], n, m;
    printf("Enter the order of matrix A:\n");
    scanf("%d, %d", &m, &n);
    printf("Enter the order of matrix B:\n");
    scanf("%d, %d", &p, &q);
    printf("Enter the elements of A:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        scanf("%d", &a[i][j]);
        }
    }
    printf("Enter the elements of B:\n");
    for(i=0;i<p;i++){
        for(j=0;j<q;j++){
        scanf("%d", &b[i][j]);
        }
    }

    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        c[i][j]=a[i][j]+b[i][j];
        }
    }
    printf("Elements of C are:\n");
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
        printf("%d\t", c[i][j]);
        }
    }

    if(m)
return 0;
}
