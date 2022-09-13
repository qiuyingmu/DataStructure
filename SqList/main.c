#include "SqList.h"

int main()
{
    SqList La, Lb, list;
    Status flag;
    int n,i;
    ElemType e;

    flag = InitList(&La);
    if(flag == OK)
    {
        printf("List init sucess!\n");
    }
    else
    {
        printf("Fail code is %d . ",flag);
    }
    flag = InitList(&Lb);
    if(flag == OK)
    {
        printf("List init sucess!\n");
    }
    else
    {
        printf("Fail code is %d . ",flag);
    }
    printf("Input La's n:");
    scanf("%d",&n);
    printf("\nPlease input %d elements:\n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&e);
        flag=ListInsert(&La,i,e);
    }
    printf("Input Lb's n:");
    scanf("%d",&n);
    printf("\nPlease input %d elements:\n",n);
    for(i=1; i<=n; i++)
    {
        scanf("%d",&e);
        flag=ListInsert(&Lb,i,e);
    }

    //求La和Lb的并集
    list = SetUnion(La, Lb);
    printf("Union is:\n");
    ListOutput(list);
    ListOutput(La);
    ListOutput(Lb);
    //求有序La和Lb的并集
    list = SetUnionOrderly(La, Lb);
    printf("Orderly union is:\n");
    ListOutput(list);
    ListOutput(La);
    ListOutput(Lb);

    //求La和Lb的交集
    list = SetIntersection(La, Lb);
    printf("Intersection is:\n");
    ListOutput(list);
    ListOutput(La);
    ListOutput(Lb);

    //求La和Lb的差集
    list = SetDifference(La, Lb);
    printf("Difference is:\n");
    ListOutput(list);
    ListOutput(La);
    ListOutput(Lb);

    //回收内存
    free(La.elem);
    free(Lb.elem);
    return 0;
}
