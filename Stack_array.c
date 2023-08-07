#include <stdio.h>
#include <stdlib.h>

struct stack{
    int* array;
    int size;
    int capacity;
};

struct stack* stack_initializer(int new_stack_size)
{
    struct stack* stack = (struct stack*) malloc(sizeof(struct stack));

    if (stack == NULL)
    {
        printf("**memory allocation error**\n");
        exit;
    }
    
    stack->array = (int*) malloc(new_stack_size * sizeof(int));
    if (stack->array == NULL)
    {
        printf("**array memory allocation failure**\n");
        exit;
    }
    stack->size = 0;
    stack->capacity = new_stack_size;

    printf("\nsize of stack = %d\n", stack->size);
    printf("stack MAX capacity = %d\n", stack->capacity);
    printf("**stack initialization successful**\n");

    return stack;
}

void stack_push(struct stack* stack, int new_top_data)
{
    int extra_space = stack->capacity - stack->size;

    if (stack->size == stack->capacity)
    {
        printf("\n**stack is full! Please increase stack size before element addition**\n");
        return;
    }
    
    printf("\nsize before element addition = %d\n", stack->size);
    stack->array[stack->size] = new_top_data;
    stack->size = stack->size + 1;
    printf("size after element addition = %d\n", stack->size);
    
    printf("**element push operation successful**\n");
}

void stack_pop(struct stack* stack)
{
    int extra_space = stack->capacity - stack->size;

    if (stack->size > 0) {
        stack->size = stack->size - 1;
    } else {
        printf("\n**Error: Stack is empty. Cannot pop.**\n");
        return;
    }
    
    printf("\n**Element pop operation successful**\n");

    // auto shrinker
    if (extra_space >= 6)
    {
        stack->array = (int*) realloc(stack->array, (stack->capacity - 5) * sizeof(int));
        stack->capacity = stack->capacity - 5;
    }
}

void stack_resizer(struct stack** stack, int new_stack_size)
{
    int old_stack_size = (*stack)->capacity;

    printf("\ncurrent stack MAX capacity = %d\n", (*stack)->capacity);

    (*stack)->array = (int*) realloc((*stack)->array, (new_stack_size*sizeof(int)));
    (*stack)->capacity = new_stack_size;

    printf("new stack MAX capacity = %d\n", (*stack)->capacity);

    if ((*stack)->capacity != 0 && (*stack)->capacity > old_stack_size)
    {
        printf("**stack resizing successful**\n");
    }
}

int stack_peek(struct stack* stack)
{   
    if (stack->size == 0 || stack->capacity == 0)
    {
        printf("\n**stack is empty**\n");
        return -1;
    }
    
    int org_top = stack->size - 1;
    printf("\nelement at the top of the stack = %d\n", stack->array[org_top]);

    return stack->array[org_top];
}

int stack_isempty_or_full_checker(struct stack* stack)
{
    if (stack->size == 0)
    {
        printf("\n**stack is empty**\n");

        return -1;
    }
    else if (stack->size != stack->capacity)
    {
        printf("\n**stack is not empty**\n");

        return 0;
    }
    else
    {
        printf("\n**stack is full**\n");

        return 1;
    }
}

void stack_printer(struct stack* stack)
{
    if (stack_isempty_or_full_checker(stack) == -1)
    {
        return;
    }
    
    printf("\ncurrent stack structure\n");

    for (int i = 0; i < stack->size; i++)
    {
        printf("value at %d = %d\n", i, stack->array[i]);
    }
}

int main()
{
    int mode;
    int new_top_data, new_stack_size, peeked_element;
    struct stack* stack;

    printf("This program implements the data structure stack using Dynamic arrays.\n");

    printf("following are the Options avaliable for list manipulation:\n1.Initialize stack.\n2.push a new element to the stack.\n3.pop the top element from the stack.\n4.resize stack (incremental only).\n5.peek top of stack.\n6.check if stack is empty or not.\n7.Re-print operations panel.\n8.EXIT.\n");
    

    while(mode != 10)
    {
        printf("please enter the operation you want to perform\n");
        scanf("%d", &mode);

        switch (mode)
        {
        case 1:
            printf("please enter the MAX capacity of the stack you want: \n");
            scanf("%d", &new_stack_size);

            stack = stack_initializer(new_stack_size);
            break;

        case 2:
            printf("please enter the data of the elment you would like to push in stack: \n");
            scanf("%d", &new_top_data);

            stack_push(stack, new_top_data);
            break;

        case 3:
            printf("poping the top-most element in stack :\n");

            stack_pop(stack);
            break;

        case 4:
            printf("please enter the new MAX capacity of the stack for resizing: \n");
            scanf("%d", &new_stack_size);

            stack_resizer(&stack, new_stack_size);
            break;

        case 5:
            peeked_element = stack_peek(stack);
            break;

        case 6:
            stack_isempty_or_full_checker(stack);
            break;

        case 7:
            printf("following are the Options avaliable for list manipulation:\n1.Re-Initialize stack.\n2.push a new element to the stack.\n3.pop the top element from the stack.\n4.resize stack (incremental only).\n5.peek top of stack.\n6.check if stack is empty or not.\n7.Re-print operations panel.\n8.EXIT.\n");
            break;

        case 8:
            goto exit;
            break;

        case 9:
            stack_printer(stack);
            break;

        default:
            printf("operation not found!!! please check the operations list and try again.\n");
            break;
        }
    }

    exit:
    return 0;
}



/*
FOR TESTING ONLY
    stack = stack_initializer(5);
    stack_isempty_or_full_checker(stack);
    stack_push(stack, 100);
    stack_push(stack, 200);
    stack_push(stack, 300);
    stack_push(stack, 400);
    stack_push(stack, 500);
    stack_push(stack, 200);
    stack_isempty_or_full_checker(stack);
    stack_printer(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_pop(stack);
    stack_isempty_or_full_checker(stack);
    stack_printer(stack);
    stack_peek(stack);
    stack_resizer(&stack, 10);
*/