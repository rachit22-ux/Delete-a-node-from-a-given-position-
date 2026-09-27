#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

int main() {
    struct Node *head = NULL, *newNode, *temp, *prev;
    int n, i, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        newNode = (struct Node *)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &newNode->data);

        newNode->next = NULL;

        if (head == NULL) {
            head = newNode;
        } else {
            temp = head;

            while (temp->next != NULL) {
                temp = temp->next;
            }

            temp->next = newNode;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    if (pos == 1) {
        temp = head;
        head = head->next;
        free(temp);
    } 
    else {
        temp = head;
        for (i = 1; i < pos - 1; i++) {
            temp = temp->next;
        }

        prev = temp->next;
        temp->next = prev->next;
        free(prev);
    }

    printf("Linked List after deletion: ");

    temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");

    return 0;
}

