#include <stdio.h>

int main(void) {
    int n, a[100], key, low, high, mid, comparisons = 0, found = -1;

    printf("Enter number of employee IDs: ");
    scanf("%d", &n);
    if (n < 1 || n > 100) {
        printf("Invalid number of IDs. Enter 1 to 100.\n");
        return 1;
    }

    printf("Enter %d employee IDs in ascending order:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter employee ID to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;
    while (low <= high) {
        mid = low + (high - low) / 2;
        comparisons++;
        if (a[mid] == key) {
            found = mid;
            break;
        } else if (key < a[mid]) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }

    if (found != -1)
        printf("Employee ID found at position %d.\n", found + 1);
    else
        printf("Employee ID not found.\n");
    printf("Number of comparisons: %d\n", comparisons);
    return 0;
}
