#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node in the polynomial list
struct Node {
    int coeff;
    int power;
    struct Node* next;
    struct Node* prev;
};

// Function to create a new node
struct Node* createNode(int coeff, int power) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = newNode->prev = NULL;
    return newNode;
}

// Function to insert a term into the polynomial list
void insertTerm(struct Node* header, int coeff, int power) {
    struct Node* newNode = createNode(coeff, power);
    struct Node* temp = header->next;

    while (temp->next != header) {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = header;
    header->prev = newNode;
}

// Function to display the polynomial
void displayPolynomial(struct Node* header) {
    struct Node* temp = header->next;

    while (temp != header) {
        printf("%dx^%d ", temp->coeff, temp->power);
        if (temp->next != header) {
            printf("+ ");
        }
        temp = temp->next;
    }

    printf("\n");
}

// Function to add two polynomials
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* resultHeader = createNode(0, 0);

    struct Node* temp1 = poly1->next;
    struct Node* temp2 = poly2->next;

    while (temp1 != poly1 && temp2 != poly2) {
        if (temp1->power > temp2->power) {
            insertTerm(resultHeader, temp1->coeff, temp1->power);
            temp1 = temp1->next;
        } else if (temp1->power < temp2->power) {
            insertTerm(resultHeader, temp2->coeff, temp2->power);
            temp2 = temp2->next;
        } else {
            insertTerm(resultHeader, temp1->coeff + temp2->coeff, temp1->power);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }

    while (temp1 != poly1) {
        insertTerm(resultHeader, temp1->coeff, temp1->power);
        temp1 = temp1->next;
    }

    while (temp2 != poly2) {
        insertTerm(resultHeader, temp2->coeff, temp2->power);
        temp2 = temp2->next;
    }

    return resultHeader;
}

int main() {
    struct Node* poly1Header = createNode(0, 0);
    struct Node* poly2Header = createNode(0, 0);

    int coeff, power;
    char choice;

    printf("Enter the first polynomial (in the format coeff power, separated by spaces, enter 'q' to quit): \n");
    do {
        scanf("%d %d", &coeff, &power);
        insertTerm(poly1Header, coeff, power);
        printf("Enter another term (or 'q' to quit): ");
        scanf(" %c", &choice);
    } while (choice != 'q' && choice != 'Q');

    printf("\nEnter the second polynomial (in the format coeff power, separated by spaces, enter 'q' to quit): \n");
    do {
        scanf("%d %d", &coeff, &power);
        insertTerm(poly2Header, coeff, power);
        printf("Enter another term (or 'q' to quit): ");
        scanf(" %c", &choice);
    } while (choice != 'q' && choice != 'Q');

    struct Node* resultHeader = addPolynomials(poly1Header, poly2Header);

    printf("\nResultant Polynomial: ");
    displayPolynomial(resultHeader);

    // Free allocated memory
    struct Node* temp = poly1Header->next;
    while (temp != poly1Header) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(poly1Header);

    temp = poly2Header->next;
    while (temp != poly2Header) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(poly2Header);

    temp = resultHeader->next;
    while (temp != resultHeader) {
        struct Node* next = temp->next;
        free(temp);
        temp = next;
    }
    free(resultHeader);

    return 0;
}
