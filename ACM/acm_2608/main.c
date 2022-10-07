#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char data[50];
    struct Node* next;
}LNode, *LinkList;

LinkList InitList(int nums);
void OutPut(LinkList link);
void DeleteLink(LinkList link);

int main()
{
    LinkList link;
    int nums;

    scanf("%d", &nums);
    link = InitList(nums);
    DeleteLink(link);
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
        scanf("%s", rear->data);
        tail->next = rear;
        tail = rear;
    }
    return link;
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
        printf("%s ", print->data);
        print = print->next;
    }
}

void DeleteLink(LinkList link)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        return;
    }
    LinkList tail, del;
    tail = link;
    while(tail->next)
    {
        del = tail->next;
        while(del->next)
        {
            if(strcmp(tail->next->data, del->next->data) == 0)
            {
                LinkList subsequent;
                subsequent = del->next;
                del->next = subsequent->next;
                free(subsequent);
                subsequent = NULL;
            }
            else
            {
                del = del->next;
            }
        }
        tail = tail->next;
    }
}
