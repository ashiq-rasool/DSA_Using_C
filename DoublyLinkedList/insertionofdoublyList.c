#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
};

int addAtBeg(struct Node** head, int data)
{
    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        return 0;
    }

    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = *head;

    // The old head must point back to the new first node.
    if (*head != NULL)
    {
        (*head)->prev = newNode;
    }

    // Update the caller's head pointer to the new first node.
    *head = newNode;
    return 1;
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
    head->next = second;
    head->prev = NULL;

    second->data = 20;
    second->next = third;
    second->prev = head;

    third->data = 30;
    third->next = NULL;
    third->prev = second;

    if (!addAtBeg(&head, 100))
    {
        perror("malloc");
        freeList(head);
        return 1;
    }

    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d <->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    freeList(head);
    printf("Doubly linked list memory freed successfully.\n");
    return 0;
}
