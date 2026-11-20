#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
};

int search(struct Node* head, int value)
{
    while (head != NULL)
    {
        if (head->data == value)
        {
            return 1;
        }
        head = head->next;
    }

    return 0;
}

int main()
{
    struct Node* head = malloc (sizeof(struct Node));
    struct Node* second = malloc (sizeof(struct Node));
    struct Node* third = malloc (sizeof(struct Node));

    head -> data = 10;
    head -> next = second;
    head -> prev = NULL;

    second -> data = 20;
    second -> next = third;
    second -> prev = head;

    third -> data = 30;
    third -> next = NULL;
    third -> prev = second;

    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d <->", temp -> data);
        temp = temp -> next;
    }
    int value;
    printf("\nEnter the value to search in the doubly linked list: ");
    if (scanf("%d", &value) != 1)
    {
        free(head);
        free(second);
        free(third);
        return 1;
    }
    if (search(head, value))
    {
        printf("Value %d found in the doubly linked list.\n", value);
    }
    else
    {
        printf("Value %d not found in the doubly linked list.\n", value);
    }

    printf("NULL\n");   
    free(head);
    free(second);
    free(third);

    printf("\nDoubly Linked List created and memory freed successfully.\n");

    return 0;
}