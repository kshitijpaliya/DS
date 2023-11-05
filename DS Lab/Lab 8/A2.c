#include <stdio.h>
#include <string.h>

// Function to reverse a string
void reverse(char str[]) {
    int length = strlen(str);
    int i, j;

    for (i = 0, j = length - 1; i < j; i++, j--) {
        char temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Function to add two long positive integers
void add(char num1[], char num2[], char result[]) {
    int carry = 0;
    int i = 0;

    int len1 = strlen(num1);
    int len2 = strlen(num2);

    reverse(num1);
    reverse(num2);

    while (i < len1 || i < len2) {
        int digit1 = (i < len1) ? (num1[i] - '0') : 0;
        int digit2 = (i < len2) ? (num2[i] - '0') : 0;

        int sum = digit1 + digit2 + carry;
        result[i] = (sum % 10) + '0';
        carry = sum / 10;

        i++;
    }

    if (carry) {
        result[i] = carry + '0';
        i++;
    }

    result[i] = '\0';

    reverse(result);
}

int main() {
    char num1[100], num2[100], result[101];

    printf("Enter the first long positive integer: ");
    scanf("%s", num1);

    printf("Enter the second long positive integer: ");
    scanf("%s", num2);

    add(num1, num2, result);

    printf("The sum is: %s\n", result);

    return 0;
}
