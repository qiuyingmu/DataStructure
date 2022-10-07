#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} LNode, *LinkList;

LinkList CreateLink();
void SameElementDelete(LinkList link);
void OutPut(LinkList link);

int main()
{
    LinkList link;
    if(!(link = CreateLink()))
    {
        return 1;
    }
    SameElementDelete(link);
    OutPut(link);
    return 0;
}

LinkList CreateLink()
{
    int dataNums;
    LinkList link, rear, tail;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        return NULL;
    }
    link->data = 0;
    link->next = NULL;
    scanf("%d", &dataNums);
    tail = link;
    for(int i = 0; i < dataNums; i++)
    {
        rear = (LinkList)malloc(sizeof(LNode));
        if(rear == NULL)
        {
            return NULL;
        }
        scanf("%d", &rear->data);
        rear->next = NULL;
        tail->next = rear;
        tail = tail->next;
    }
    return link;
}

void SameElementDelete(LinkList link)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL || link->next->next == NULL)
    {
        return;
    }
    LinkList del;
    int element = link->next->data;
    del = link->next;
    while(del->next)
    {
        if(element == del->next->data)
        {
            LinkList same;
            same = del->next;
            del->next = same->next;
            free(same);
            same = NULL;
        }
        else
        {
            element = del->next->data;
            del = del->next;
        }
    }
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
