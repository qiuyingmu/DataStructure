#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}LNode, *LinkList;

int JointLink(LinkList linkA, LinkList linkB);
LinkList InitList(int nums);
void OutPut(LinkList link);

int main()
{
    LinkList linkA, linkB;
    int m, n;

    scanf("m=%d", &m);
    linkA = InitList(m);
    getchar();
    getchar();
    scanf("n=%d", &n);
    getchar();
    linkB = InitList(n);
    int joint = JointLink(linkA, linkB);
    if(joint == 1)
    {
        OutPut(linkA);
    }
    else if(joint == 2)
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
    LinkList link, tail, rear;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        return NULL;
    }
    link->next = NULL;
    tail = link;
    for(int i = 0; i < nums; i++)
    {
        rear = (LinkList)malloc(sizeof(LNode));
        if(rear == NULL)
        {
            return NULL;
        }
        int data;
        scanf("%d", &data);
        rear->data = data;
        rear->next = NULL;
        tail->next = rear;
        tail = rear;
    }
    tail->next = link;
    return link;
}

int JointLink(LinkList linkA, LinkList linkB)
{
    LinkList tailA, tailB;

    if(!linkA || !linkB)
    {
        return 0;
    }
    if(!(linkA->next))
    {
        return 1;
    }
    if(!(linkB->next))
    {
        return 2;
    }
    tailA = linkA;
    while(tailA->next != linkA)
    {
        tailA = tailA->next;
    }
    tailB = linkB;
    while(tailB->next != linkB)
    {
        tailB = tailB->next;
    }
    tailA->next = linkB->next;
    tailB->next = linkA;
    free(linkB);
    return 1;
}

void OutPut(LinkList link)
{
    LinkList print;
    print = link->next;
    while(print != link)
    {
        printf("%d ", print->data);
        print = print->next;
    }
}
