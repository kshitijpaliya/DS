#include<stdio.h>

int main()
{
    char str1[100], str2[100];
    int m, n, i=0, j=0;

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
    printf("%d, %d\n", m, n);

    for(i=0;i<n;i++){
        str1[m+i]=str2[i];
    }

    puts(str1);
    return 0;
}
