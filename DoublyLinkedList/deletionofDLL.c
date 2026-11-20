#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int deleteValue(struct Node** head, int value)
{
    struct Node* current = *head;

    while (current != NULL && current->data != value)
    {
        current = current->next;
    }

    if (current == NULL)
    {
        return 0;
    }

    // Connect both neighboring nodes around the node being removed.
    if (current->prev != NULL)
    {
        current->prev->next = current->next;
    }
    else
    {
        *head = current->next;
    }

    if (current->next != NULL)
    {
        current->next->prev = current->prev;
    }

    free(current);
    return 1;
}

void printList(const struct Node* head)
{
    while (head != NULL)
    {
        printf("%d <-> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

void freeList(struct Node* head)
{
    while (head != NULL)
    {
        struct Node* next = head->next;
        free(head);
        head = next;
    }
}

int main(void)
{
    struct Node* head = malloc(sizeof(struct Node));
    struct Node* second = malloc(sizeof(struct Node));
    struct Node* third = malloc(sizeof(struct Node));

    if (head == NULL || second == NULL || third == NULL)
    {
        perror("malloc");
        free(head);
        free(second);
        free(third);
        return 1;
    }

    head->data = 10;
    head->prev = NULL;
    head->next = second;

    second->data = 20;
    second->prev = head;
    second->next = third;

    third->data = 30;
    third->prev = second;
    third->next = NULL;

    printf("List before deletion: ");
    printList(head);

    int value;
    printf("Enter the value to delete: ");
    if (scanf("%d", &value) != 1)
    {
        fprintf(stderr, "Invalid input.\n");
        freeList(head);
        return 1;
    }

    if (deleteValue(&head, value))
    {
        printf("%d was deleted.\n", value);
    }
    else
    {
        printf("%d was not found.\n", value);
    }

    printf("List after deletion: ");
    printList(head);

    freeList(head);
    return 0;
}