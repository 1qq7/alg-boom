#include <stdlib.h>

#include "sqlist.h"
#include "status.h"

#define MaxSize 100

Status InitList_Sq(SqList &L)
{
    L.elem = new int[MaxSize];
    if(!L.elem) exit(OVERFLOW);
    L.length = 0;
    return OK;
}


void DestroyList(SqList &L)
{
    if(L.elem) delete L.elem;
}


void ClearList(SqList &L)
{
    L.length = 0;
}


int GetLength(const SqList &L)
{
    return L.length;
}


Status IsEmpty(const SqList &L)
{
    return L.length == 0 ? TRUE:FALSE;
}


Status GetElem(const SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    return OK;
}


int LocateElem(const SqList &L, int e)
{
    for (int i=0; i<L.length; ++i){
        if(L.elem[i] == e) return i+1;
    }
    return 0;
}


int InsertElem(SqList &L, int i, int e)
{
    if (i < 1 || i>L.length+1) return ERROR;
    if (MaxSize == L.length) return ERROR;
    // 元素后移
    for (int j=L.length; j>=i; j--){
        L.elem[j] = L.elem[j-1];
    }
    L.elem[i-1] = e;
    L.length++;
    return OK;
}


int ListDelete_Sq(SqList &L, int i, int &e)
{
    if (i < 1 || i > L.length) return ERROR;
    e = L.elem[i-1];
    // 把第i+1到L.length之间的元素前移
    for (int j=i; j<L.length; ++j){
        L.elem[j-1] = L.elem[j];
    }
    L.length--;
    return OK;
}