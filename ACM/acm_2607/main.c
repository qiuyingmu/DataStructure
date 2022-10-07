#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}LNode, *LinkList;

LinkList InitList(int nums);
void Exchange(LinkList link, int location);
void OutPut(LinkList link);

int main()
{
    LinkList link;
    int nums, location;

    scanf("%d", &nums);
    link = InitList(nums);
    scanf("%d", &location);
    Exchange(link, location);
    OutPut(link);
    return 0;
}

LinkList InitList(int nums)
{
    LinkList link, rear, tail;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        return NULL;
    }
    tail = link;
    for(int i = 0; i < nums; i++)
    {
        rear = (LinkList)malloc(sizeof(LNode));
        if(rear == NULL)
        {
            return NULL;
        }
        rear->next = NULL;
        scanf("%d", &(rear->data));
        tail->next = rear;
        tail = rear;
    }
    return link;
}

void Exchange(LinkList link, int location)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        return;
    }
    if(link->next->next == NULL)
    {
        return;
    }
    int count = 1;
    LinkList exchange;
    exchange = link;
    while(exchange)
    {
        exchange = exchange->next;
        count++;
        if(count == location)
        {
            break;
        }
    }
    if(count < location)
    {
        return;
    }
    LinkList subsequent;
    subsequent = exchange->next;
    exchange->next = subsequent->next;
    subsequent->next = exchange->next->next;
    exchange->next->next = subsequent;
}

void OutPut(LinkList link)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        return;
    }
    LinkList print;
    print = link->next;
    while(print)
    {
        printf("%d ", print->data);
        print = print->next;
    }
}
