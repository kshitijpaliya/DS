#include<stdio.h>

int main()
{
    char str1[100], str2[100];
    int m, n, i, j=0, a, b;

    printf("Enter the 1st String:\n");
    gets(str1);
    //printf("Enter the 2nd String:\n");
    //gets(str2);

    while(str1[i]!='\0'){
        i++;
        m=i;
    }

/*     while(str2[j]!='\0'){
 *         j++;
 *         n=j;
 *     }
 */

    printf("Enter the starting index:\n");
    scanf("%d", &a);

    printf("Enter the ending index:\n");
    scanf("%d", &b);

    for(i=0;i<=b-a;i++)
    {
        str1[a+i]=str1[b+i];
    }
    puts(str1);

/*     for(i=0;i<index;i++)
 *     {
 *         str3[i]=str1[i];
 *     }
 *
 *     for(i=0;i<n;i++)
 *     {
 *         str3[index+i]=str2[i];
 *     }
 *
 *     for(i=0;i<m-index;i++)
 *     {
 *         str3[index+n+i]=str1[index+i];
 *     }
 */




    return 0;
}


