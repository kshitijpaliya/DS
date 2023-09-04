#include<stdio.h>
struct Student{
   char name[10];
   int roll_no;
   int grade;
   } s[50];

int main()
{
    int n, i, p;
    printf("Enter the number of students:\n");
    scanf("%d", &n);
    for(i=0;i<n;i++)
    {
        scanf("%s", s[i].name);
        scanf("%d", &s[i].roll_no);
        scanf("%d", &s[i].grade);
    }

    printf("The details of students are:\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\n", s[i].name);
        printf("%d\n", s[i].roll_no);
        printf("%d\n", s[i].grade);
    }
//    p=n;
//    display(s, p);
    int temp;
    for(i=0;i<n-1;i++)
    {
        for(int j=0;j<n-1-i;j++)
        {
            if(s.roll_no[j]>s.roll_no[j+1]){
            temp=s.roll_no[j];
            s.roll_no[j]=s.roll_no[j+1];
            s.roll_no[j+1]=temp;
        }
    }
}



//void display(struct Student s, int n)
//{
//    printf("The details of students are:\n");
//    for(int i=0;i<n;i++)
//    {
//        printf("%s", s[i].name);
//        printf("%d", s[i].roll_no);
//        printf("%d", s[i].grade);
//    }
}
