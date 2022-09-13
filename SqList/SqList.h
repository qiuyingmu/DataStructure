#ifndef SQLIST_H_INCLUDED
#define SQLIST_H_INCLUDED

/*˳�����㷨ʵ��*/
/*ͷ�ļ�*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>
/*��������*/
#define TRUE   1
#define FALSE  0
#define OK  1
#define ERROR  0
#define OVERFLOW  -2
#define LIST_INIT_SIZE 100  /*�洢�ռ�ĳ�ʼ������*/
#define LISTINCREAMENT 10   /*�洢�ռ�ķ������� */
/*�Զ����������� */
typedef int Status;    /*�������ؽ������ */
typedef int ElemType;  /*Ԫ�����Ͷ��� */

typedef struct
{
    ElemType *elem;     /*���ַ(��ָ��elem��ʾ�� */
    int  length;        /*���ȣ������ж��ٸ�Ԫ�أ� */
    int  listsize;      /*��ǰ����ı�ߴ磨Ԫ�ص�λ��*/
} SqList;             /*˳�������      */

/*--------����ԭ������------*/
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

/*---˳���Ĳ����ĺ���ʵ��----- */
Status InitList(SqList *L)
{
    /*��ʼ���յ�˳��� */
    L->elem=(ElemType*) malloc(LIST_INIT_SIZE*sizeof(ElemType));
    if (!L->elem)
        exit(OVERFLOW);          /*����ʧ�ܣ��������� */
    L->length=0;                 /*����Ԫ�ط��룬�ձ� */
    L->listsize=LIST_INIT_SIZE;  /*��ߴ�=��ʼ������*/
    return OK;
}/*InitList*/

Status LocateElem(SqList L,ElemType e)
{
    /*��˳���L�в���Ԫ��ֵΪe��Ԫ�أ����ҳɹ�����Ԫ�ص������±꣬���򷵻�-1*/
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
    /*��˳���L�ĵ�i��Ԫ��ǰ������Ԫ��e*/
    ElemType *newbase,*q,*p;
    if(i<1||i>L->length+1) return ERROR;/*����i�ĺϷ��� */

    if(L->length>=L->listsize)/*�ռ䲻�������ӿռ� */
    {
        newbase=(ElemType*)realloc(L->elem,(L->listsize+LISTINCREAMENT)*sizeof(ElemType));
        if(newbase==NULL)
            exit(OVERFLOW);
        L->elem =newbase;
        L->listsize =L->listsize +LISTINCREAMENT;
    }
    /*����Ԫ��*/
    q=&(L->elem[i-1]);  /*qָ�����λ�ã�����i��Ԫ�صĵ�ַ */
    for (p=&L->elem[L->length-1]; p>=q; --p )
        *(p+1) = *p ;   /*�ӱ�����һ��Ԫ�ص���i��Ԫ�����κ���*/

    *q=e ;            /*����e*/
    ++L->length ;     /*����1*/
    return OK;
}/*ListInsert*/

Status ListDelete(SqList *L,int i,ElemType *e)
{
    /*��˳���L��ɾ���� i ��Ԫ�أ��� e ������ֵ*/
    ElemType *p,*q;
    if (i<1||i>L->length)
        exit(ERROR);   /* i ֵ���Ϸ������� */
    p=&L->elem[i-1];            /* pָ��ɾ��Ԫ�صĵ�ַ*/
    *e=*p;
    q=L->elem+L->length-1;       /* qָ���β��*/
    for(++p; p<=q; p++)
        *(p-1) = *p;          /*��ɾԪ�غ��������ǰ�ƣ����ӵ�i+1�������һ������ǰ��*/
    --L->length ;              /*��-1*/
    return OK;
}/*ListDelete*/

void ListOutput(SqList L)
{
    /*���˳����е�Ԫ��*/
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
    int La_len = La.length, Lb_len = Lb.length;//La,Lb��
    int i;

    for(i = 1; i <= Lb_len; i++)
    {
        e = Lb.elem[i - 1]; //ȡLb�ĵ�i��Ԫ�ظ�ֵ��e
        if(LocateElem(La, e) == -1) //La�в����ں�e��ͬ��Ԫ�أ����뵽La��β��
        {
            ListInsert(&La, ++La_len, e);
        }
    }
    return La;
}

SqList SetUnionOrderly(SqList La,SqList Lb)
{
    //A = AUB ����
    SqList LLa, LLb; //����La,Lb;
    CopyList(La, &LLa);
    CopyList(Lb, &LLb);
    ElemType ea, eb;
    int LLa_len = LLa.length, LLb_len = LLb.length;//La,Lb��
    int i, j;

    for(i = 1; i <= LLb_len; i++)
    {
        eb = LLb.elem[i - 1]; //ȡLb�ĵ�i��Ԫ�ظ�ֵ��eb
        for(j = 1; j <= LLa_len; j++)
        {
            ea = LLa.elem[j - 1]; //ȡLa�ĵ�j��Ԫ�ظ�ֵ��ea
            if(eb <= ea)
            {
                ListInsert(&LLa, j, eb);
                LLa_len++;
                ListDelete(&LLb, i, &eb);
                LLb_len--;
                i--;
                break;
            }
        }
    }
    return LLa;
}

SqList SetIntersection(SqList La, SqList Lb)
{
    //A = AnB
    SqList LLa, LLb; //����La,Lb;
    CopyList(La, &LLa);
    CopyList(Lb, &LLb);
    ElemType e;
    int LLa_len = LLa.length;//La��
    int i;

    for(i = 1; i <= LLa_len; i++)
    {
        e = LLa.elem[i - 1];//ȡLa�ĵ�i��Ԫ�ظ�ֵ��e
        if(LocateElem(LLb, e) == -1)//Lb�в����ں�e��ͬ��Ԫ�أ�ɾ��La�е�e(λ��Ϊi)
        {
            ListDelete(&LLa, i, &e);
            i--; //ɾ��������ĵ���
            LLa_len--;
        }
    }
    return LLa;
}

SqList SetDifference(SqList La, SqList Lb)
{
    //A = A-B
    SqList LLa, LLb; //����La,Lb;
    CopyList(La, &LLa);
    CopyList(Lb, &LLb);
    ElemType e, flag_e;
    int LLa_len = LLa.length;//La��
    int i, flag = 0;

    for(i = 1; i <= LLa_len; i++)
    {
        flag_e = e = LLa.elem[i - 1];//ȡLa�ĵ�i��Ԫ�ظ�ֵ��e
        flag = LocateElem(LLb, e) + 1; //����λ��
        if(flag != 0 /*λ��*/)//Lb�д��ں�e��ͬ��Ԫ�أ�ɾ��La�е�e(λ��Ϊi),ɾ��Lb�е�e(λ��Ϊflag)
        {
            ListDelete(&LLa, i, &e);
            ListDelete(&LLb, flag, &flag_e);
            i--; //ɾ��������ĵ���
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

