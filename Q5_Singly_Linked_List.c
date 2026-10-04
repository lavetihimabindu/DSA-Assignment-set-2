#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int roll;
    struct Node *next;
} Node;

Node *head = NULL;

void display(void) {
    Node *p = head;
    if (!p) { printf("List is empty.\\n"); return; }
    printf("List: ");
    while (p) { printf("%d ", p->roll); p = p->next; }
    printf("\\n");
}

void insertBeginning(int roll) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\\n"); return; }
    n->roll = roll; n->next = head; head = n;
    display();
}

void insertEnd(int roll) {
    Node *n = malloc(sizeof(Node));
    if (!n) { printf("Memory allocation failed.\\n"); return; }
    n->roll = roll; n->next = NULL;
    if (!head) head = n;
    else {
        Node *p = head;
        while (p->next) p = p->next;
        p->next = n;
    }
    display();
}

void searchRoll(int roll) {
    Node *p = head; int pos = 1;
    while (p) {
        if (p->roll == roll) {
            printf("Roll number %d found at position %d.\\n", roll, pos);
            return;
        }
        p = p->next; pos++;
    }
    printf("Roll number %d not found.\\n", roll);
}

void deleteRoll(int roll) {
    Node *p = head, *prev = NULL;
    while (p && p->roll != roll) { prev = p; p = p->next; }
    if (!p) { printf("Roll number %d not available.\\n", roll); return; }
    if (!prev) head = p->next;
    else prev->next = p->next;
    free(p);
    printf("Deleted roll number %d.\\n", roll);
    display();
}

int main(void) {
    int choice, roll;
    do {
        printf("\\n1.Insert beginning 2.Insert end 3.Search 4.Delete 5.Display 6.Exit\\nChoice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1: printf("Enter roll number: "); scanf("%d", &roll); insertBeginning(roll); break;
            case 2: printf("Enter roll number: "); scanf("%d", &roll); insertEnd(roll); break;
            case 3: printf("Enter roll number to search: "); scanf("%d", &roll); searchRoll(roll); break;
            case 4: printf("Enter roll number to delete: "); scanf("%d", &roll); deleteRoll(roll); break;
            case 5: display(); break;
            case 6: printf("Exiting.\\n"); break;
            default: printf("Invalid choice.\\n");
        }
    } while (choice != 6);

    while (head) { Node *t = head; head = head->next; free(t); }
    return 0;
}
