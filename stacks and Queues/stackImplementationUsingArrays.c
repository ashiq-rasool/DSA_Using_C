#include <stdio.h>
#define MAX 5

int stack_arr[MAX];
int top = -1;
void push(int data)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        printf("Pushed element: %d\n", data);
    }
    top = top + 1;
    stack_arr[top] = data;
}
int main()
{
    push(10);
    return 0;
}