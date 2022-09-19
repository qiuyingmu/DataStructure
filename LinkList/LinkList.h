#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define HeadFlag 0x3F3F3F3F
/*数据结构的定义*/
typedef enum
{
    false = 0,
    true = 1
}bool;

typedef int ElemType;

typedef struct node
{
    ElemType data;
    struct node* next;
}LNode, *LinkList;

/*函数声明*/
void OutPut(LinkList link); //输出单链表
void Free(LinkList link); //释放单链表
LinkList InitList();
bool ListHeadInsert(LinkList link, ElemType elem); //头插法
bool ListTailInsert(LinkList link, ElemType elem); //尾插法
bool ListFond(LinkList link, ElemType elem); //查找单链表中是否有elem
bool ListDelete(LinkList link, ElemType elem); //删除单链表中的elem（删除单链表顺序中的第一个）
LinkList IntersectionList(LinkList linkA, LinkList linkB); //两个单链表的交集
LinkList UnionSetList(LinkList linkA, LinkList linkB); //两个单链表的并集
LinkList DifferenceSet(LinkList linkA, LinkList linkB); //两个单链表的差集

/*操作集函数实现*/
LinkList InitList()
{
    LinkList link;

    link = (LinkList)malloc(sizeof(LNode));
    if(link == NULL)
    {
        printf("LinkList error.\n");
        return NULL;
    }
    link->data = HeadFlag;
    link->next = NULL;

    return link;
}

bool ListHeadInsert(LinkList link, ElemType elem)
{
    if(link == NULL)
    {
        printf("This LinkList has not been initialized.\n");
        return false;
    }
    LinkList rear;
    rear = (LinkList)malloc(sizeof(LNode));
    if(rear == NULL)
    {
        printf("Insert error.\n");
        return false;
    }
    rear->data = elem;
    rear->next = link->next;
    link->next = rear;
    return true;
}

bool ListTailInsert(LinkList link, ElemType elem)
{
    if(link == NULL)
    {
        printf("This LinkList has not been initialized.\n");
        return false;
    }
    LinkList rear, tail;
    rear = (LinkList)malloc(sizeof(LNode));
    if(rear == NULL)
    {
        printf("Insert error.\n");
        return false;
    }
    rear->data = elem;
    rear->next = NULL;
    tail = link->next;
    if(tail == NULL)
    {
        link->next = rear;
    }
    else
    {
        while(tail->next)
        {
            tail = tail->next;
        }
        tail->next = rear;
    }
    return true;
}

bool ListFond(LinkList link, ElemType elem)
{
    if(link == NULL)
    {
        printf("This LinkList has not been initialized.\n");
        return false;
    }
    else if(link->next == NULL)
    {
        printf("This LinkList is empty.\n");
        return false;
    }
    LinkList fond = link->next;
    while(fond)
    {
        if(fond->data == elem)
        {
            return true;
        }
        else
        {
            fond = fond->next;
        }
    }
    return false;
}

bool ListDelete(LinkList link, ElemType elem)
{
    if(link == NULL)
    {
        printf("This LinkList has not been initialized.\n");
        return false;
    }
    else if(link->next == NULL)
    {
        printf("This LinkList is empty.\n");
        return false;
    }
    LinkList fond = link->next, del;
    if(fond->data == elem)
    {
        link->next = fond->next;
        free(fond);
        fond = del = NULL;
        return true;
    }
    else
    {
        while(fond)
        {
            if(fond->next->data == elem)
            {
                del = fond->next;
                fond->next = del->next;
                free(del);
                del = NULL;
                return true;
            }
            else
            {
                fond = fond->next;
            }
        }
        return false;
    }
}

LinkList IntersectionList(LinkList linkA, LinkList linkB)
{
    if(!linkA && !linkB) //不存在A,B单链表
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A单链表为空，但B单链表不为空
    {
        LinkList linkC = NULL;
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B单链表为空，但A单链表不为空
    {
        LinkList linkC = NULL;
        return linkC;
    }
    LinkList linkC, head; //A,B单链表都不为空
    linkC = InitList();
    for(head = linkA->next; head; head = head->next)
    {
        if(ListFond(linkB, head->data) == true)
        {
            ListTailInsert(linkC, head->data);
        }
    }
    return linkC;
}

LinkList UnionSetList(LinkList linkA, LinkList linkB)
{
    if(!linkA && !linkB) //不存在A,B单链表
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A单链表为空，但B单链表不为空
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkB->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B单链表为空，但A单链表不为空
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkA->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    LinkList linkC, head; //A,B单链表都不为空
    linkC = InitList();
    for(head = linkA->next; head; head = head->next)
    {
        ListTailInsert(linkC, head->data);
    }
    for(head = linkB->next; head; head = head->next)
    {
        if(ListFond(linkC, head->data) == false)
        {
            ListTailInsert(linkC, head->data);
        }
    }
    return linkC;
}

LinkList DifferenceSet(LinkList linkA, LinkList linkB)
{
    if(!linkA && !linkB) //不存在A,B单链表
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A单链表为空，但B单链表不为空
    {
        LinkList linkC = NULL;
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B单链表为空，但A单链表不为空
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkA->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    LinkList linkC, head; //A,B单链表都不为空
    linkC = InitList();
    for(head = linkA->next; head; head = head->next)
    {
        if(ListFond(linkB, head->data) == false)
        {
            ListTailInsert(linkC, head->data);
        }
    }
    return linkC;
}

void OutPut(LinkList link)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        printf("This single linked list is empty.\n");
        return;
    }
    LinkList print;
    print = link->next;
    while(print)
    {
        printf("%d ", print->data);
        print = print->next;
    }
    printf("\n");
}

void Free(LinkList link)
{
    if(!link)
    {
        return;
    }
    if(link->next == NULL)
    {
        printf("This single linked list is empty.\n");
        free(link);
        link = NULL;
        return;
    }
    LinkList head;
    head = link;
    while(head)
    {
        LinkList release;
        release = head;
        head = head->next;
        free(release);
        release = NULL;
    }
    head = NULL;
}

#endif // LINKLIST_H_INCLUDED
