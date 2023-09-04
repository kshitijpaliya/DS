#include <stdio.h>

// Define the structure for Time
struct Time {
    int hour;
    int min;
    int sec;
};

// Function to add two Time objects
struct Time addTime(struct Time t1, struct Time t2) {
    struct Time result;

    result.sec = t1.sec + t2.sec;
    result.min = t1.min + t2.min;
    result.hour = t1.hour + t2.hour;

    if (result.sec >= 60) {
        result.sec -= 60;
        result.min++;
    }

    if (result.min >= 60) {
        result.min -= 60;
        result.hour++;
    }

    if (result.hour >= 24) {
        result.hour -= 24;
    }

    return result;
}

// Function to find the difference between two Time objects
struct Time findDifference(struct Time t1, struct Time t2) {
    struct Time result;

    int t1InSeconds = t1.hour * 3600 + t1.min * 60 + t1.sec;
    int t2InSeconds = t2.hour * 3600 + t2.min * 60 + t2.sec;
    int diffInSeconds = t1InSeconds - t2InSeconds;

    if (diffInSeconds < 0) {
        diffInSeconds += 24 * 3600; // 24 hours in a day
    }

    result.hour = diffInSeconds / 3600;
    result.min = (diffInSeconds % 3600) / 60;
    result.sec = diffInSeconds % 60;

    return result;
}

// Function to read a Time object from the user
void readTime(struct Time *t) {
    printf("Enter hour: ");
    scanf("%d", &t->hour);

    printf("Enter minute: ");
    scanf("%d", &t->min);

    printf("Enter second: ");
    scanf("%d", &t->sec);
}

// Function to display a Time object
void displayTime(struct Time t) {
    printf("%02d:%02d:%02d\n", t.hour, t.min, t.sec);
}

int main() {
    struct Time time1, time2, sum, difference;

    printf("Enter first time:\n");
    readTime(&time1);

    printf("Enter second time:\n");
    readTime(&time2);

    sum = addTime(time1, time2);
    difference = findDifference(time1, time2);

    printf("\nSum of times: ");
    displayTime(sum);

    printf("Difference between times: ");
    displayTime(difference);

    return 0;
}
