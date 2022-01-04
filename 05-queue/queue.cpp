#include "./queue.h"


SqQueue::SqQueue(int size)
{
    MAXSIZE = size;
    base = new ElemT[size];
    len = front = rear = 0;
}

SqQueue::~SqQueue()
{
    if (base) delete [] base;
    base = nullptr;
}

int SqQueue::length()
{
    return len;
}

status SqQueue::push(ElemT &e)
{
    if (len == MAXSIZE) return status::fail;
    base[rear] = e;
    rear = (rear + 1) % MAXSIZE;
    len++;
    return status::ok;
}

status SqQueue::pop(ElemT &e)
{
    if (len == 0) return status::fail;
    e = base[front];
    front = (front + 1) % MAXSIZE;
    len--;
    return status::ok;
}


linkQueue::linkQueue()
{
    len = 0;
    front = new node;
    front->next = nullptr;
    rear = front->next;
}

linkQueue::~linkQueue()
{
    node* tmp;
    while (front)
    {
        tmp = front;
        front = front->next;
        delete tmp;
    }    
}


status linkQueue::push(ElemT &e)
{
    node* new_node = new node;
    new_node->data = e;
    new_node->next = nullptr;
    rear = new_node;
    rear = rear->next;
    len++;
    return status::ok;
}


status linkQueue::pop(ElemT &e)
{
    if (front->next == nullptr) return status::fail;
    e = front->next->data;
    node * tmp = front->next;
    front->next = tmp->next;
    delete tmp;
    len--;
    return status::ok;
} 