#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}LNode, *LinkList;

LinkList InitList(int nums);
int Mergelink(LinkList linkA, LinkList linkB);
void OutPut(LinkList link);

int main()
{
    int numsA, numsB;
    LinkList linkA, linkB;

    scanf("%d", &numsA);
    linkA = InitList(numsA);
    scanf("%d", &numsB);
    linkB = InitList(numsB);
    int mark = Mergelink(linkA, linkB);
    if(mark == 1)
    {
        OutPut(linkA);
    }
    else if(mark == 2)
    {
        OutPut(linkB);
    }
    else
    {
        ;
    }
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

int Mergelink(LinkList linkA, LinkList linkB)
{
    if(!linkA || !linkB)
    {
        return 0;
    }
    if(linkA->next == NULL)
    {
        return 2;
    }
    if(linkB->next == NULL)
    {
        return 1;
    }
    LinkList tailA, tailB;
    tailA = linkA;
    tailB = linkB;
    while(tailA->next && tailB->next)
    {
        LinkList merge, subsequent;
        if(tailA->next->data < tailB->next->data)
        {
            tailA = tailA->next;
        }
        else if(tailA->next->data == tailB->next->data)
        {
            tailA = tailA->next;
            tailB = tailB->next;
        }
        else
        {
            merge = tailB->next;
            tailB->next = merge->next;
            subsequent = tailA->next;
            merge->next = subsequent;
            tailA->next = merge;
        }
    }
    if(tailB->next == NULL)
    {
        return 1;
    }
    if(tailA->next == NULL)
    {
        tailA->next = tailB->next;
        tailB->next = NULL;
    }
    return 1;
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
