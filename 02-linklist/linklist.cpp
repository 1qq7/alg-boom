#include "linklist.h"
#include <stdio.h>

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
    return 0;
}


/**
 * 链表已经存在，求链表表长，不包含头结点。
*/
int ListLength_L(LinkList L)
{
    LinkList p = L;
    int i = 0;              // 使用计数器i维护相对头结点next的次数
    while (p->next) {       // 如果p是最后一个结点，p->next == nullptr
        p = p->next;
        i++;
    }
    return i;
}


/**
 * 链表已经存在，读取第i个元素。1 <= i <= len
*/
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L->next;
    int j = 1;
    while (p && j < i) {
        p = p->next;
        j++;
    }
    // 检查非法位置
    if (!p || j>i) return Status::fail;
    e = p->data;
    return Status::ok;
}

#if 0
Lnode *LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    while(p && p->data != e) {
        p = p->next;
    }
    return p;
}
#else
int LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 1;
    while(p && p->data != e) {
        p = p->next;
        i++;
    }
    if (!p) return 0;
    return i;
}
#endif


Status InsertElem_L(LinkList L, int i, ElemType e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || j > i-1) return Status::fail;
    Lnode* new_node = new Lnode;
    new_node->next = p->next;
    p->next = new_node;
    new_node->data = e;
    return Status::ok;
}


Status DeleteElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    while (p->next && j < i-1) {
        p = p->next;
        j++;
    }
    if (!(p->next) || j < i -1) return Status::fail;
    Lnode* node_i = p->next;
    e = node_i->data;
    p->next = node_i->next;
    delete node_i;
    return Status::ok; 
}


void CreateList_H(LinkList &L, int n)
{
    L = new Lnode;
    L->next = nullptr;
    for (int i=n; i>0; i--) {
        Lnode* new_node = new Lnode;    // 创建新结点
        new_node->next = L->next;       // 新结点的next 指向头结点的next
        L->next = new_node;             // 头结点指向新结点
    }
}


void CreateList_R(LinkList &L, int n)
{
    L = new Lnode;
    L->next = nullptr;
    LinkList p = L;                     // 这里用p跟踪尾结点，初始p指向头结点
    for (int i=0; i<n; i++) {
        Lnode* new_node = new Lnode;    // 创建新结点
        new_node->next = p->next;       // 新结点的next 指向尾结点的next
        p->next = new_node;             // 尾结点的下一个是新结点
        p = new_node;                   // 更新尾结点指针
    }
}

int main()
{
    LinkList L = nullptr;
    InitList_L(L);
    int len = ListLength_L(L);
    InsertElem_L(L, 1, 1);
    len = ListLength_L(L);
    printf("len %d\n", len);
}