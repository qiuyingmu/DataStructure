#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}LNode, *LinkList;

typedef struct SNode
{
    LinkList hand;
}*Stack;

typedef struct QNode
{
    LinkList front;
    LinkList rear;
}*Queue;

Stack InitStack();
Queue InitQueue();
int IsEmptyStack(Stack stack);
int IsEmptyQueue(Queue queue);
int PushStack(Stack stack, int data);
int PopStack(Stack stack);
int EnQueue(Queue queue, int data);
int DeQueue(Queue queue);
void ReverseQueue(Queue queue);
void Display(Queue queue);


int main()
{
    Queue queue;

    queue = InitQueue();
    ReverseQueue(queue);
    Display(queue);
    return 0;
}

void ReverseQueue(Queue queue)
{
    Stack stack;

    stack = InitStack();
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        int data;
        scanf("%d", &data);
        EnQueue(queue, data);
    }
    while(!IsEmptyQueue(queue))
    {
        int data;
        data = DeQueue(queue);
        PushStack(stack, data);
    }
    while(!IsEmptyStack(stack))
    {
        int data;
        data = PopStack(stack);
        EnQueue(queue, data);
    }
}

Stack InitStack()
{
    Stack stack;

    stack = (Stack)malloc(sizeof(struct SNode));
    if(!stack)
    {
        return NULL;
    }
    stack->hand = NULL;
    return stack;
}

Queue InitQueue()
{
    Queue queue;

    queue = (Queue)malloc(sizeof(struct QNode));
    if(!queue)
    {
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
}

int IsEmptyStack(Stack stack)
{
    if(!stack)
    {
        return 1;
    }
    if(stack->hand == NULL)
    {
        return 1;
    }
    return 0;
}

int IsEmptyQueue(Queue queue)
{
    if(!queue)
    {
        return 1;
    }
    if(queue->front == NULL && queue->rear == NULL)
    {
        return 1;
    }
    return 0;
}

int PushStack(Stack stack, int data)
{
    if(!stack)
    {
        return 0;
    }
    LinkList tail;

    tail = (LinkList)malloc(sizeof(LNode));
    if(tail == NULL)
    {
        return 0;
    }
    tail->data = data;
    tail->next = stack->hand;
    stack->hand = tail;
    return 1;
}

int PopStack(Stack stack)
{
    if(IsEmptyStack(stack))
    {
        return 0;
    }
    else
    {
        LinkList link;

        link = stack->hand;
        stack->hand = link->next;
        int data = link->data;
        free(link);
        return data;
    }
}

int EnQueue(Queue queue, int data)
{
    if(!queue)
    {
        return 0;
    }
    LinkList link;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        return 0;
    }
    link->data = data;
    link->next = NULL;
    if(IsEmptyQueue(queue))
    {
        queue->front = queue->rear = link;
    }
    else
    {
        queue->rear->next = link;
        queue->rear = link;
    }
    return 1;
}

int DeQueue(Queue queue)
{
    if(IsEmptyQueue(queue))
    {
        return 0;
    }
    else
    {
        LinkList link;

        link = queue->front;
        queue->front = link->next;
        if(link->next == NULL)
        {
            queue->rear = NULL;
        }
        int data = link->data;
        free(link);
        return data;
    }
}

void Display(Queue queue)
{
    if(!queue)
    {
        return;
    }
    if(IsEmptyQueue(queue))
    {
        return;
    }
    LinkList print;
    print = queue->front;
    while(print)
    {
        printf("%d ", print->data);
        print = print->next;
    }
}
