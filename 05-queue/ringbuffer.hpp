#pragma once
#include <vector>
typedef int ElemT;

class RingBuffer
{
private:
    ElemT *base;
    unsigned int len;
    unsigned int MAXSIZE;
    unsigned int rear;
public:
    RingBuffer(unsigned int size);
    ~RingBuffer();
    void push(ElemT v);
    void get(std::vector<ElemT> &datas);
};

RingBuffer::RingBuffer(unsigned int size)
{
    MAXSIZE = size;
    base = new ElemT[MAXSIZE];
    len = rear = 0;
}

RingBuffer::~RingBuffer()
{
    if (base) delete [] base;
    base = nullptr;
}

void RingBuffer::push(ElemT v)
{
    base[rear] = v;
    rear = (rear + 1) % MAXSIZE;
    len++;
    len = len > MAXSIZE ? MAXSIZE:len;
}

void RingBuffer::get(std::vector<ElemT> &datas)
{
    for (unsigned int i = 0; i < len - rear; i++){
        datas.push_back(base[rear + i]);
    }
    for (unsigned int i = 0; i < rear; i++){
        datas.push_back(base[i]);
    }
}