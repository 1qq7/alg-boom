#include "linklist.h"


int InitList_L(LinkList &L)
{
    L = new Lnode;
    L->next = nullptr;
    return 0;
}


bool ListEmpty(LinkList L)
{
    return L->next == nullptr;
}


int DestoryList_L(LinkList &L)
{
    LinkList p;
    while(L) {
        p = L;
        L = L->next;
        delete p;
    }
    return 0;
}


int ClearList_L(LinkList L)
{
    DestoryList_L(L->next);
    L->next = nullptr;
    return 0;
}


int ListLength_L(LinkList L)
{
    int len = 0;
    LinkList p = L->next;
    while (p) {
        len++;
        p = p->next;
    }
    return len;
}

Status GetElem_L(LinkList L, int i, ElemType &e)
{
    int j=1;
    while (j <= i) {
        if (L == nullptr) break;
        L = L->next;
        j++;
    }

    if (i != j) return Status::fail;

}