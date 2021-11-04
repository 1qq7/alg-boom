#pragma once

typedef int ElemType;

typedef struct Lnode{
    ElemType data;
    struct Lnode *next;
}Lnode, *LinkList;

enum class Status {ok=0, fail=1};