#pragma once

typedef int ElemT;
enum class status {ok, fail};


class SqQueue
{
private:
    ElemT *base;
    int front;
    int rear;
    int MAXSIZE;
    int len;
public:
    SqQueue(int size);
    ~SqQueue();
    int length();
    status push(ElemT &e);
    status pop(ElemT &e);
};


class linkQueue
{
private:
    struct node {
        ElemT data;
        node * next;
    };
    int len;
    node* front;
    node* rear;
public:
    linkQueue();
    ~linkQueue();
    status push(ElemT &e);
    status pop(ElemT &e);
};