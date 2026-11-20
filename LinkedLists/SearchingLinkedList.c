#include<stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node* next;
};

int search(struct Node* head, int key)
{
    int position = 1;

    while (head != NULL)
    {
        if (head -> data == key)
        {
            return position;
        }
        head = head -> next;
        position++;
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

    second -> data = 20;
    second -> next = third;

    third -> data = 30;
    third -> next = NULL;

    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d->", temp -> data);
        temp = temp -> next;
    }
 int key;
    printf("\nEnter the key to search: ");
    scanf("%d", &key);
    int result = search(head, key);
    if (result != 0)
    {
        printf("Key %d found at position %d.\n", key, result);
    }
    else
    {
        printf("Key %d not found in the linked list.\n", key);
    }

    free(head);
    free(second);
    free(third);

    return 0;
}