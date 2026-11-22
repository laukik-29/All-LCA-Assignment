#include <stdio.h>

#define SUBJECTS 3
#define MAX_STUDENTS 50

struct Student {
    int rollNo;
    char name[50];
    float marks[SUBJECTS];
    float total;
    float percentage;
};

int main(void)
{
    struct Student students[MAX_STUDENTS];
    int count, i, j;

    printf("Enter number of students (maximum %d): ", MAX_STUDENTS);
    if (scanf("%d", &count) != 1 || count < 1 || count > MAX_STUDENTS) {
        printf("Invalid number of students.\n");
        return 1;
    }

    for (i = 0; i < count; i++) {
        students[i].total = 0;

        printf("\nStudent %d\n", i + 1);
        printf("Enter roll number: ");
        scanf("%d", &students[i].rollNo);

        printf("Enter name: ");
        scanf(" %49[^\n]", students[i].name);

        for (j = 0; j < SUBJECTS; j++) {
            printf("Enter marks in subject %d (out of 100): ", j + 1);
            scanf("%f", &students[i].marks[j]);
            students[i].total += students[i].marks[j];
        }

        students[i].percentage = students[i].total / SUBJECTS;
    }

    printf("\n%-8s %-20s %-10s %-12s %-10s\n",
           "Roll No", "Name", "Total", "Percentage", "Result");
    printf("-----------------------------------------------------------------\n");

    for (i = 0; i < count; i++) {
        int passed = 1;

        for (j = 0; j < SUBJECTS; j++) {
            if (students[i].marks[j] < 35) {
                passed = 0;
                break;
            }
        }

        printf("%-8d %-20s %-10.2f %-12.2f %-10s\n",
               students[i].rollNo, students[i].name, students[i].total,
               students[i].percentage, passed ? "PASS" : "FAIL");
    }

    return 0;
}
