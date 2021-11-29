#include "dulinklist.h"

DuLnode* GetElemP_Dul(DuLinkList L, int i)
{
    int j = 0;
    DuLinkList p = L;
    while (p && j<i) {
        p = p->next;
        j++;
    }
    if (!p || j > i) return nullptr;
    return p;
}


Status ListInsert_Dul(DuLinkList L, int i, ElemType e)
{
    DuLinkList p = GetElemP_Dul(L, i);
    if (!p) return Status::fail;
    DuLnode* new_node = new DuLnode;
    p->prior->next = new_node;
    new_node->prior = p->prior;
    new_node->next = p;
    p->prior = new_node;
    return Status::ok;
}


Status ListDelete_Dul(DuLinkList L, int i, ElemType &e)
{
    DuLinkList p = GetElemP_Dul(L, i);
    if (!p) return Status::fail;
    e = p->data;
    p->prior->next = p->next;
    p->next->prior = p->prior;
    delete p;
    return Status::ok;
}


