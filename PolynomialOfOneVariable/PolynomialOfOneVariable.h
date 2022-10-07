#ifndef POLYNOMIALOFONEVARIABLE_H_INCLUDED
#define POLYNOMIALOFONEVARIABLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define HEADERDATA 0x3F3F3F3F //ͷ���ϵ����ָ���ı�־

/*���ݽṹ����*/
typedef enum
{
    false = 0,
    true = 1
}bool;

typedef struct Node
{
    int coef; //ϵ��
    int index; //ָ��
    struct Node* next;
}PolyNode, *Polynomial;

/*��������������*/
Polynomial InitPoly(); //һԪ����ʽ��ͷ����ʼ��
bool InsertPoly(Polynomial poly, int coef, int index); //β�巨
bool ReadPoly(Polynomial poly); //һԪ����ʽ�Ķ�ȡ
Polynomial AddPoly(Polynomial polyA, Polynomial polyB); //һԪ����ʽ���

/*����������ʵ��*/
Polynomial InitPoly()
{
    Polynomial poly;

    poly = (Polynomial)malloc(sizeof(PolyNode));
    if(poly == NULL)
    {
        printf("poly error.\n");
        return NULL;
    }
    poly->coef = poly->index = HEADERDATA;
    poly->next = NULL;
    return poly;
}

bool InsertPoly(Polynomial poly, int coef, int index)
{
    if(poly == NULL)
    {
        printf("The unary polynomial was not created successfully.\n");
        return false;
    }
    Polynomial rear, tail;
    rear = (Polynomial)malloc(sizeof(PolyNode));
    if(rear == NULL)
    {
        printf("rear error.\n");
        return false;
    }
    rear->coef = coef;
    rear->index = index;
    rear->next = NULL;
    tail = poly;
    if(tail->next == NULL) //һԪ����ʽû��Ԫ��
    {
        tail->next = rear;
        return true;
    }
    else //һԪ����ʽ��Ԫ��
    {
        while(tail->next) //��β���
        {
            tail = tail->next;
        }
        tail->next = rear;
        return true;
    }
}

bool ReadPoly(Polynomial poly)
{
    int nums;

    scanf("%d", &nums);
    for(int i = 0; i < nums; i++)
    {
        int coef, index;

        scanf("%d %d", &coef, &index);
        if(InsertPoly(poly, coef, index) == false) //���ݲ���
        {
            printf("Data read error!\n");
            return false;
        }
    }
    return true;
}

Polynomial AddPoly(Polynomial polyA, Polynomial polyB)
{
    if(!polyA && !polyB)
    {
        printf("Neither monadic polynomial exists.\n");
        return NULL;
    }
    Polynomial polyC;
    polyC = (Polynomial)malloc(sizeof(PolyNode));
    if(polyC == NULL)
    {
        printf("polyC error.\n");
        return false;
    }
    polyC->next = NULL;
    polyC->coef = polyB = HEADERDATA;
    Polynomial rearA, rearB;
    rearA = polyA;
    rearB = polyB;
    while(rearA && rearB)
    {

    }
}

#endif // POLYNOMIALOFONEVARIABLE_H_INCLUDED
