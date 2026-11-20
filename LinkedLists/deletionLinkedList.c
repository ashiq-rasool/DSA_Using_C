#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int deleteValue(struct Node** head, int value)
{
    struct Node* current = *head;
    struct Node* previous = NULL;

    while (current != NULL && current->data != value)
    {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
    {
        return 0;
    }

    if (previous == NULL)
    {
        *head = current->next;
    }
    else
    {
        previous->next = current->next;
    }

    free(current);
    return 1;
}

void printList(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d->", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main()
{
    struct Node* head = malloc (sizeof(struct Node));
    struct Node* second = malloc (sizeof(struct Node));
    struct Node* third = malloc (sizeof(struct Node));

    head -> data = 10;
    head -> next = second;

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    printf("List before deletion: ");
    printList(head);

    int value;
    printf("Enter the value to delete: ");
    if (scanf("%d", &value) != 1)
    {
        printf("Invalid input.\n");
        return 1;
    }

    if (deleteValue(&head, value))
    {
        printf("%d deleted.\n", value);
    }
    else
    {
        printf("%d not found.\n", value);
    }

    printf("List after deletion: ");
    printList(head);

    while (head != NULL)
    {
        struct Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}