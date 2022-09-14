#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

/*顺序表的算法实现*/
/*头文件*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
/*常量定义*/
#define TRUE   1
#define FALSE  0
#define OK  1
#define ERROR  0
#define OVERFLOW  -2
#define LIST_INIT_SIZE 100  /*存储空间的初始分配量*/
#define LISTINCREAMENT 10   /*存储空间的分配增量 */
/*自定义数据类型 */
typedef int Status;    /*函数返回结果类型 */
typedef int ElemType;  /*元素类型定义 */

typedef struct
{
    ElemType *elem;     /*表基址(用指针elem表示） */
    int  length;        /*表长度（表中有多少个元素） */
    int  listsize;      /*当前分配的表尺寸（元素单位）*/
} SqList;             /*顺序表类型      */

/*--------函数原型声明------*/
void CopyList(SqList L, SqList* copyList);
Status InitList(SqList *L);
Status ListInsert(SqList *L,int i,ElemType e);
Status ListDelete(SqList *L,int i,ElemType *e);
void ListOutput(SqList L);
Status  LocateElem(SqList L,ElemType e);
SqList SetUnion(SqList La,SqList Lb);
SqList SetUnionOrderly(SqList La,SqList Lb);
SqList SetIntersection(SqList La, SqList Lb);
SqList SetDifference(SqList La, SqList Lb);

/*---顺序表的操作的函数实现----- */
Status InitList(SqList *L)
{
    /*初始化空的顺序表 */
    L->elem=(ElemType*) malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L->elem)
        exit(OVERFLOW);          /*分配失败，结束程序 */
    L->length=0;                 /*暂无元素放入，空表 */
    L->listsize=LIST_INIT_SIZE;  /*表尺寸=初始分配量*/
    return OK;
}/*InitList*/

Status LocateElem(SqList L,ElemType e)
{
    /*在顺序表L中查找元素值为e的元素，查找成功返回元素的数组下标，否则返回-1*/
    int i=0;
    while(i<=L.length-1 && L.elem[i]!=e)
        i++;
    if (i<=L.length-1)
        return i;
    else
        return -1;
}/*LocateElem*/

Status ListInsert(SqList *L,int i,ElemType e)
{
    /*在顺序表L的第i个元素前插入新元素e*/
    ElemType *newbase,*q,*p;
    if(i<1||i>L->length+1) return ERROR;/*检验i的合法性 */

    if(L->length>=L->listsize)/*空间不够，增加空间 */
    {
        newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREAMENT)*sizeof(ElemType));
        if(newbase==NULL)
            exit(OVERFLOW);
        L->elem =newbase;
        L->listsize =L->listsize +LISTINCREAMENT;
    }
    /*插入元素*/
    q=&(L->elem[i-1]);  /*q指向插入位置，即第i个元素的地址 */
    for (p=&L->elem[L->length-1]; p>=q; --p )
        *(p+1) = *p ;   /*从表的最后一个元素到第i个元素依次后移*/

    *q=e ;            /*插入e*/
    ++L->length ;     /*表长加1*/
    return OK;
}/*ListInsert*/

Status ListDelete(SqList *L,int i,ElemType *e)
{
    /*在顺序表L中删除第 i 个元素，用 e 返回其值*/
    ElemType *p,*q;
    if (i<1||i>L->length)
        exit(ERROR);   /* i 值不合法，返回 */
    p=&L->elem[i-1];            /* p指向被删除元素的地址*/
    *e=*p;
    q=L->elem+L->length-1;       /* q指向表尾的*/
    for(++p; p<=q; p++)
        *(p-1) = *p;          /*待删元素后面的依次前移，即从第i+1个到最后一个依次前移*/
    --L->length ;              /*表长-1*/
    return OK;
}/*ListDelete*/

void ListOutput(SqList L)
{
    /*输出顺序表中的元素*/
    int i;
    if(L.length==0)
        printf("List is NULL!\n");
    else
    {
        for(i=0; i<L.length; i++)
            printf("%d ",L.elem[i]);
        printf("\n");
    }
}

SqList SetUnion(SqList La,SqList Lb)
{
    //A = AUB
    ElemType e;
    int La_len = La.length, Lb_len = Lb.length;//La,Lb表长
    int i;

    for(i = 1; i <= Lb_len; i++)
    {
        e = Lb.elem[i - 1]; //取Lb的第i个元素赋值给e
        if(LocateElem(La, e) == -1) //La中不存在和e相同的元素，插入到La的尾部
        {
            ListInsert(&La, ++La_len, e);
        }
    }
    return La;
}

SqList SetUnionOrderly(SqList La,SqList Lb)
{
    //有序线性表的合并
    ElemType ea, eb;
    SqList Lc;
    int laLocation = 0, lbLocation = 0, lcLocation = 0;

    InitList(&Lc);
    while(laLocation <= (La.length - 1) && lbLocation <= (Lb.length - 1))
    {
        ea = La.elem[laLocation];
        eb = Lb.elem[lbLocation];
        if(ea <= eb)
        {
            ListInsert(&Lc, lcLocation + 1, ea);
            laLocation++;
            lcLocation++;
        }
        else
        {
            ListInsert(&Lc, lcLocation + 1, eb);
            lbLocation++;
            lcLocation++;
        }
    }
    while(laLocation <= La.length-1)
    {
        ea=La.elem[laLocation];
        ListInsert(&Lc, lcLocation + 1, ea);
        laLocation++;
        lcLocation++;
    }
    while(lbLocation <= Lb.length-1)
    {
        eb=Lb.elem[lbLocation];
        ListInsert(&Lc, lcLocation + 1, eb);
        lbLocation++;
        lcLocation++;
    }

    return Lc;
}

SqList SetIntersection(SqList La, SqList Lb)
{
    //A = AnB
    SqList LLa, LLb; //复制La,Lb;防止将原本的线性表内容更改
    CopyList(La, &LLa);
    CopyList(Lb, &LLb);
    ElemType e;
    int LLa_len = LLa.length;//La表长
    int i;

    for(i = 1; i <= LLa_len; i++)
    {
        e = LLa.elem[i - 1];//取La的第i个元素赋值给e
        if(LocateElem(LLb, e) == -1)//Lb中不存在和e相同的元素，删除La中的e(位置为i)
        {
            ListDelete(&LLa, i, &e);
            i--; //删除操作后的调整
            LLa_len--;
        }
    }
    return LLa;
}

SqList SetDifference(SqList La, SqList Lb)
{
    //A = A-B
    SqList LLa, LLb; //复制La,Lb;
    CopyList(La, &LLa);
    CopyList(Lb, &LLb);
    ElemType e, flag_e;
    int LLa_len = LLa.length;//La表长
    int i, flag = 0;

    for(i = 1; i <= LLa_len; i++)
    {
        flag_e = e = LLa.elem[i - 1];//取La的第i个元素赋值给e
        flag = LocateElem(LLb, e) + 1; //处理位置
        if(flag != 0 /*位置*/)//Lb中存在和e相同的元素，删除La中的e(位置为i),删除Lb中的e(位置为flag)
        {
            ListDelete(&LLa, i, &e);
            ListDelete(&LLb, flag, &flag_e);
            i--; //删除操作后的调整
            LLa_len--;
        }
    }
    return LLa;

}

void CopyList(SqList L, SqList* copyList)
{
    Status flag;
    int i;

    flag = InitList(copyList);
    if(flag == OK)
    {
        printf("List copy sucess!\n");
    }
    else
    {
        printf("Fail code is %d . ",flag);
    }
    for(i = 1; i <= L.length; i++)
    {
        ListInsert(copyList, i, L.elem[i - 1]);
    }
}

#endif // SQLIST_H_INCLUDED

