#include "linklist.h"
#include <stdio.h>

/**
 * 初始化一个链表
*/
void InitList_L(LinkList &L)
{
    L = new Lnode;
    L->next = nullptr;
}

/**
 * 前插法创建指定长度的链表
*/
void CreateList_H(LinkList &L, int n)
{
    L = new Lnode;
    L->next = nullptr;
    for (int i = n; i > 0; i--)
    {
        Lnode *new_node = new Lnode; // 创建新结点
        new_node->next = L->next;    // 新结点的next 指向头结点的next
        L->next = new_node;          // 头结点指向新结点
    }
}

/**
 * 后插法创建指定长度的链表
*/
void CreateList_R(LinkList &L, int n)
{
    L = new Lnode;
    L->next = nullptr;
    LinkList p = L; // 这里用p跟踪尾结点，初始p指向头结点
    for (int i = 0; i < n; i++)
    {
        Lnode *new_node = new Lnode; // 创建新结点
        new_node->next = p->next;    // 新结点的next 指向尾结点的next
        p->next = new_node;          // 尾结点的下一个是新结点
        p = new_node;                // 更新尾结点指针
    }
}

/**
 * 判读链表是否为空
*/
bool ListEmpty(LinkList L)
{
    return L->next == nullptr;
}

/**
 * 销毁链表，释放所有结点，包括头结点。
*/
void DestoryList_L(LinkList &L)
{
    LinkList p;
    while (L)
    {
        p = L;
        L = L->next;
        delete p;
    }
}

/**
 * 清空链表，不包括头结点。delete a[1] -- a[n]
*/
void ClearList_L(LinkList L)
{
    DestoryList_L(L->next);
}

/**
 * 求链表表长，不包含头结点。
*/
int ListLength_L(LinkList L)
{
    LinkList p = L;
    int i = 0; // 使用计数器i维护相对头结点next的次数
    while (p->next)
    { // 如果p是最后一个结点，p->next == nullptr
        p = p->next;
        i++;
    }
    return i;
}

/**
 * 读取第i个元素
*/
Status GetElem_L(LinkList L, int i, ElemType &e)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    // 检查非法位置
    if (!p || i < 1)
        return Status::fail;
    e = p->data;
    return Status::ok;
}

/**
 * 返回第i个位置的结点指针。a[0] ... a[i] ... a[n]
 * if i<0 or i>n return nullptr
*/
Lnode *GetElemP_L(LinkList L, int i)
{
    LinkList p = L;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (i < 0)
        return nullptr;
    return p;
}

/**
 * 返回最后一个结点的指针
*/
Lnode *GetEndElemP(LinkList L)
{
    LinkList p = L;
    while (p->next)
    {
        p = p->next;
    }
    return p;
}

/**
 * 查找元素，找到返回结点位置索引，否则0
*/
int LocateElem_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    int i = 1;
    while (p && p->data != e)
    {
        p = p->next;
        i++;
    }
    if (!p)
        return 0;
    return i;
}

/**
 * 查找元素，找到返回结点位置指针，否则nullptr
*/
Lnode *LocateElemP_L(LinkList L, ElemType e)
{
    LinkList p = L->next;
    while (p && p->data != e)
    {
        p = p->next;
    }
    return p;
}

/**
 * 在指定位置i插入元素e, 1 <= i <= n
*/
Status InsertElem_L(LinkList L, int i, ElemType e)
{
#if 0
    LinkList p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || i<1) return Status::fail;
#else
    LinkList p = GetElemP_L(L, i - 1);
    if (!p)
        return Status::fail;
#endif
    Lnode *new_node = new Lnode;
    new_node->next = p->next;
    p->next = new_node;
    new_node->data = e;
    return Status::ok;
}

/**
 * 删除指定位置i的元素，1 <= i <= n, 并返回给e。
*/
Status DeleteElem_L(LinkList L, int i, ElemType &e)
{
#if 0
    LinkList p = L;
    int j = 0;
    while (p && j < i-1) {
        p = p->next;
        j++;
    }
    if (!p || i<1 || !(p->next)) return Status::fail;
#else
    LinkList p = GetElemP_L(L, i - 1);
    if (!p || !(p->next))
        return Status::fail;
#endif
    Lnode *node_i = p->next;
    e = node_i->data;
    p->next = node_i->next;
    delete node_i;
    return Status::ok;
}

int main()
{
    Status status;
    int len = 0;
    LinkList L = nullptr;
    ElemType e = 233;

    InitList_L(L);
    printf("Testing InsertElem_L\n");
    for (int i = -1; i < 10; i++){
       status = InsertElem_L(L, i, e);
       printf("Insert pos %d; %s; Length %d\n", i, status==Status::ok ? "Valid!" : "Invalid!", ListLength_L(L));
    }
    printf("Testing DeleteElem_L\n");
    for (int i = 10; i > -2; i--){
       status = DeleteElem_L(L, i, e);
       printf("Delete pos %d; %s; Length %d\n", i, status==Status::ok ? "Valid!" : "Invalid!", ListLength_L(L));
    }

    DestoryList_L(L);
    if (L == nullptr) printf("DestoryList_L\n");

}