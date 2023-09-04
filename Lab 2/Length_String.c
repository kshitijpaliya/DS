#include<stdio.h>

int main(){
    int i;
    char str[100];

    printf("Enter the String:\n");
    gets(str);

    while(str[i]!='\0'){
        i++;
    }
    printf("The length of the string is %d", i);

    return 0;
}
