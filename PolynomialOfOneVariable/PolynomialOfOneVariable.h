#ifndef POLYNOMIALOFONEVARIABLE_H_INCLUDED
#define POLYNOMIALOFONEVARIABLE_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#define HEADERDATA 0x3F3F3F3F //头结点系数和指数的标志

/*数据结构定义*/
typedef enum
{
    false = 0,
    true = 1
}bool;

typedef struct Node
{
    int coef; //系数
    int index; //指数
    struct Node* next;
}PolyNode, *Polynomial;

/*操作集函数声明*/
Polynomial InitPoly(); //一元多项式的头结点初始化
bool InsertPoly(Polynomial poly, int coef, int index); //尾插法
bool ReadPoly(Polynomial poly); //一元多项式的读取
Polynomial AddPoly(Polynomial polyA, Polynomial polyB); //一元多项式相加

/*操作集函数实现*/
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
    if(tail->next == NULL) //一元多项式没有元素
    {
        tail->next = rear;
        return true;
    }
    else //一元多项式有元素
    {
        while(tail->next) //找尾结点
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
        if(InsertPoly(poly, coef, index) == false) //数据插入
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
