#include <stdio.h>

int main(void) {
    int n, a[100], shifts = 0;

    printf("Enter number of marks: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid number of marks. Enter 1 to 100.\n");
        return 1;
    }

    printf("Enter %d marks:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i < n; i++) {
        int key = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            shifts++;
            j--;
        }
        a[j + 1] = key;

        printf("After pass %d: ", i);
        for (int k = 0; k < n; k++)
            printf("%d ", a[k]);
        printf("\n");
    }

    printf("Sorted marks: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\nTotal element shifts: %d\n", shifts);
    return 0;
}
