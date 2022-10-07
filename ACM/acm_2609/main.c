#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}LNode, *LinkList;

LinkList InitList(int nums);
void OutPut(LinkList link);
void BubbleSort(LinkList link, int nums);

int main()
{
    LinkList link;
    int nums;

    scanf("m=%d", &nums);
    link = InitList(nums);
    BubbleSort(link, nums);
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

void BubbleSort(LinkList link, int nums)
{

    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        return;
    }

    LinkList tail;
    for(int i = 0; i < nums; i++)
    {
        tail = link;
        for(int j = nums - i - 1; j > 0; j--)
        {
            if(tail->next->data > tail->next->next->data)
            {
                LinkList subsequent;
                subsequent = tail->next;
                tail->next = subsequent->next;
                subsequent->next = tail->next->next;
                tail->next->next = subsequent;
            }
            tail = tail->next;
        }
    }
}
