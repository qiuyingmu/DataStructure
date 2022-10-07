#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
} LNode, *LinkList;

LinkList CreateLink(int dataNums);
void OutPut(LinkList link, int dataNums);

int main()
{
    LinkList link;
    int dataNums;

    scanf("%d", &dataNums);
    if(!(link = CreateLink(dataNums)))
    {
        return 1;
    }
    OutPut(link, dataNums);
    return 0;
}

LinkList CreateLink(int dataNums)
{
    LinkList link, rear;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        return NULL;
    }
    link->data = 0;
    link->next = NULL;
    for(int i = 0; i < dataNums; i++)
    {
        rear = (LinkList)malloc(sizeof(LNode));
        if(rear == NULL)
        {
            return NULL;
        }
        scanf("%d", &rear->data);
        rear->next = link->next;
        link->next = rear;
    }
    return link;
}

void OutPut(LinkList link, int dataNums)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        return;
    }
    LinkList head;
    head = link->next;
    int count = 1, nums = 0, data, element = head->data;
    scanf("%d", &data);
    while(head)
    {
        if(head->data == data)
        {
            dataNums -= nums + 1;
            head = head->next;
            break;
        }
        else if(head->data < data)
        {
            dataNums -= nums;
            break;
        }
        else
        {
            if(head->data != element)
            {
                count++;
                element = head->data;
            }
            nums++;
            head = head->next;
        }
    }
    printf("%d\n", count);
    while(dataNums)
    {
        printf("%d ", head->data);
        head = head->next;
        dataNums--;
    }
}

