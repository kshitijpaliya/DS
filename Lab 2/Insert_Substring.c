#include<stdio.h>

int main()
{
    char str1[100], str2[100], str3[100];
    int m, n, i=0, j=0, index;

    printf("Enter the 1st String:\n");
    gets(str1);
    printf("Enter the 2nd String:\n");
    gets(str2);

    while(str1[i]!='\0'){
        i++;
        m=i;
    }

    while(str2[j]!='\0'){
        j++;
        n=j;
    }

    printf("Enter the index:\n");
    scanf("%d", &index);


    for(i=0;i<index;i++)
    {
        str3[i]=str1[i];
    }

    for(i=0;i<n;i++)
    {
        str3[index+i]=str2[i];
    }

    for(i=0;i<m-index;i++)
    {
        str3[index+n+i]=str1[index+i];
    }

    puts(str3);
    return 0;
}

