#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
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

    printf("Enter any value to insert at the beginning of the linked list: ");
    int value;
    if (scanf("%d", &value) != 1)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    struct Node* newNode = malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }

    newNode->data = value;
    newNode->next = head;

    head = newNode;
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d->", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");

    while (head != NULL)
    {
        struct Node* next = head->next;
        free(head);
        head = next;
    }

    return 0;
}