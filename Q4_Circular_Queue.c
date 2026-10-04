#include <stdio.h>

#define SIZE 5
int queue[SIZE], front = -1, rear = -1;

void insert(int value) {
    if ((rear + 1) % SIZE == front) {
        printf("Queue overflow.\n");
        return;
    }
    if (front == -1)
        front = rear = 0;
    else
        rear = (rear + 1) % SIZE;
    queue[rear] = value;
    printf("Inserted: %d\n", value);
}

void deleteItem(void) {
    if (front == -1) {
        printf("Queue underflow.\n");
        return;
    }
    printf("Deleted: %d\n", queue[front]);
    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % SIZE;
}

void display(void) {
    if (front == -1) {
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue: ");
    int i = front;
    while (1) {
        printf("%d ", queue[i]);
        if (i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(void) {
    int choice, value;
    do {
        printf("\\n1.Insert 2.Delete 3.Display 4.Exit\\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2: deleteItem(); break;
            case 3: display(); break;
            case 4: printf("Exiting.\\n"); break;
            default: printf("Invalid choice.\\n");
        }
    } while (choice != 4);
    return 0;
}
