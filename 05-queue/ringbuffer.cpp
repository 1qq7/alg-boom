#include <iostream>
#include "./ringbuffer.hpp"

int main()
{
    RingBuffer buff(10);
    for (int i=0; i<100; i++){
        buff.push(i);
        std::vector<int> data;
        buff.get(data);
        for (auto v: data){
            std::cout << v << ", ";
        }
        std::cout << std::endl;
    }
}