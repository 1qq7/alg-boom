#pragma once

typedef int ElemType;

class SqStack
{
private:
    ElemType *base;
    ElemType *top;
    int stacksize;
public:
    SqStack(int size);
    ~SqStack();
    bool isEmpty();
    int length();
    void clearStack();
    void destroyStack();
    int pop(ElemType &e);
    int push(ElemType &e);

};

struct node{
    ElemType data;
    node* next;
};
class LinkStack
{
private:
    node *p;
    int len;
public:
    LinkStack():p(nullptr),len(0){};
    ~LinkStack();
    void push(ElemType &e);
    void pop(ElemType &e);
};