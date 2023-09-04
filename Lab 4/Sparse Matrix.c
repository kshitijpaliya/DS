#include <stdio.h>

struct Element
{
    int row;
    int column;
    int value;
};
int main ()
{
int sparse_matrix[5][5], i, j, size=0;

printf("Enter the elements:\n");
for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {

        scanf("%d", &sparse_matrix[i][j]);
    }
}

for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {
        if(sparse_matrix[i][j]!=0)
            size++;
    }
}

struct Element*matrix=(struct Element*)malloc(size*sizeof(struct Element));
int k =0;
for(i=0;i<5;i++)
{
    for(j=0;j<5;j++)
    {
        if(sparse_matrix[i][j]!=0)
        {
            matrix[k].row=i;
            matrix[k].column=j;
            matrix[k].value=sparse_matrix[i][j];
            k++;
        }
    }
}

for(i=0;i<size;i++)
{
    printf(" %d\t%d\t%d\n", matrix[i].row, matrix[i].column, matrix[i].value);
}
free(matrix);
return 0;
}
