#include "stack.h"

SqStack::SqStack(int size): stacksize(size)
{
    this->base = new ElemType[size];
    this->top = this->base;
}

SqStack::~SqStack()
{
    if (this->base) delete[] this->base;
    this->base =nullptr;
}

bool SqStack::isEmpty()
{
    return this->base == this->top;
}

int SqStack::length()
{
    return this->top - this->base;
}

void SqStack::clearStack()
{
    this->top = this->base;
}

void SqStack::destroyStack()
{
    if (this->base) delete[] this->base;
    this->base =nullptr;
}

int SqStack::push(ElemType &e)
{
    if (this->top - this->base == this->stacksize)
        return -1;
    *this->top = e;
    this->top++;
    return 0;
}

int SqStack::pop(ElemType &e)
{
    if (this->top == this->base)
        return -1;
    this->top--;
    e = *this->top;
    return 0;
}



LinkStack::~LinkStack()
{
    node *tmp;
    while (p){
        tmp = p;
        p = p->next;
        delete tmp;
    }
    len = 0;
}

void LinkStack::push(ElemType &e)
{
    node* new_node = new node;
    new_node->next = p->next;
    p->next = new_node;
    new_node->data = e;
    len++;
}

void LinkStack::pop(ElemType &e)
{
    node *tmp;
    if (p) {
        tmp = p;
        p = p->next;
        e = tmp->data;
        delete tmp;
        len--;
    }
}