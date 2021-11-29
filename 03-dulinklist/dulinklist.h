#pragma once

typedef int ElemType;

typedef struct DuLnode{
    ElemType data;
    struct DuLnode *prior, *next;
}DuLnode, *DuLinkList;

enum class Status {ok=0, fail=1};