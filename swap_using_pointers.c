#include <stdio.h>

void swap(int *first, int *second)
{
    int temporary = *first;
    *first = *second;
    *second = temporary;
}

int main(void)
{
    int number1, number2;

    printf("Enter two numbers: ");
    if (scanf("%d %d", &number1, &number2) != 2) {
        printf("Invalid input.\n");
        return 1;
    }

    printf("Before swapping: number1 = %d, number2 = %d\n", number1, number2);
    swap(&number1, &number2);
    printf("After swapping:  number1 = %d, number2 = %d\n", number1, number2);

    return 0;
}
