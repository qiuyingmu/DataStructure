#ifndef LINKLIST_H_INCLUDED
#define LINKLIST_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#define HeadFlag 0x3F3F3F3F
/*���ݽṹ�Ķ���*/
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

/*��������*/
void OutPut(LinkList link); //���������
void Free(LinkList link); //�ͷŵ�����
LinkList InitList();
bool ListHeadInsert(LinkList link, ElemType elem); //ͷ�巨
bool ListTailInsert(LinkList link, ElemType elem); //β�巨
bool ListFond(LinkList link, ElemType elem); //���ҵ��������Ƿ���elem
bool ListDelete(LinkList link, ElemType elem); //ɾ���������е�elem��ɾ��������˳���еĵ�һ����
LinkList IntersectionList(LinkList linkA, LinkList linkB); //����������Ľ���
LinkList UnionSetList(LinkList linkA, LinkList linkB); //����������Ĳ���
LinkList DifferenceSet(LinkList linkA, LinkList linkB); //����������Ĳ

/*����������ʵ��*/
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
    if(!linkA && !linkB) //������A,B������
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A������Ϊ�գ���B������Ϊ��
    {
        LinkList linkC = NULL;
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B������Ϊ�գ���A������Ϊ��
    {
        LinkList linkC = NULL;
        return linkC;
    }
    LinkList linkC, head; //A,B��������Ϊ��
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
    if(!linkA && !linkB) //������A,B������
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A������Ϊ�գ���B������Ϊ��
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkB->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B������Ϊ�գ���A������Ϊ��
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkA->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    LinkList linkC, head; //A,B��������Ϊ��
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
    if(!linkA && !linkB) //������A,B������
    {
        return NULL;
    }
    if(linkA->next == NULL && linkB->next != NULL) //A������Ϊ�գ���B������Ϊ��
    {
        LinkList linkC = NULL;
        return linkC;
    }
    if(linkA->next != NULL && linkB->next == NULL) //B������Ϊ�գ���A������Ϊ��
    {
        LinkList linkC, head;

        linkC = InitList();
        for(head = linkA->next; head; head = head->next)
        {
            ListTailInsert(linkC, head->data);
        }
        return linkC;
    }
    LinkList linkC, head; //A,B��������Ϊ��
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
