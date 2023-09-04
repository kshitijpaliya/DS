#include <stdio.h>
#include <string.h>

// Define the structure for a student
struct Student {
    char name[50];
    int rollNo;
    char grade;
};

// Function to read student information
void readStudent(struct Student students[], int n) {
    for (int i = 0; i < n; i++) {
        printf("Enter student name: ");
        scanf("%s", students[i].name);

        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter grade: ");
        scanf(" %c", &students[i].grade);
    }
}

void displayStudents(struct Student students[], int n) {
    printf("\nStudent Information:\n");
    printf("Name\t\tRoll No\t\tGrade\n");

    for (int i = 0; i < n; i++) {
        printf("%s\t\t%d\t\t%c\n", students[i].name, students[i].rollNo, students[i].grade);
    }
}

// Function to sort students based on roll number using Bubble Sort
void sortStudents(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                // Swap the students if they are out of order
                struct Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

    // Read student information
    readStudent(students, n);

    // Display unsorted student information
    printf("\nUnsorted Student Information:\n");
    displayStudents(students, n);

    // Sort students based on roll number
    sortStudents(students, n);

    // Display sorted student information
    printf("\nSorted Student Information by Roll Number:\n");
    displayStudents(students, n);

    return 0;
}
