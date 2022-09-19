#include "LinkList.h"

int main()
{
    int n;
    LinkList linkA, linkB, linkC;

    linkA = InitList();
    linkB = InitList();
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        ElemType elem;
        scanf("%d", &elem);
        ListTailInsert(linkA, elem);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
    {
        ElemType elem;
        scanf("%d", &elem);
        ListTailInsert(linkB, elem);
    }
    linkC = UnionSetList(linkA, linkB);
    OutPut(linkC);
    Free(linkC);
    linkC = IntersectionList(linkA, linkB);
    OutPut(linkC);
    Free(linkC);
    linkC = DifferenceSet(linkA, linkB);
    OutPut(linkC);
    Free(linkC);
    return 0;
}
