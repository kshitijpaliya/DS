#include<stdio.h>

int main()
{
    char str1[100], str2[100];
    int m, n, i=0, j=0, a, b;

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

    for(i=0;i<m;i++)
    {
        str1[i]=a;
            str2[i]=b;
            if(a>b){
                printf("String 1 is greater than String 2");
                break;
            }
            else
            if(a<b){
                printf("String 1 is smaller than String 2");
                break;
            }
            else
            if(a==b){
                printf("The Strings are equal");
                break;
            }
    }

    return 0;
}

