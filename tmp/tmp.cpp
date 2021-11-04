#include "stdio.h"

void fun(int* &v){
    v = new int(2);
}


int main()
{
    int a = 10;
    int *p = &a;
    printf("%p\n", p);

    fun(p);
    printf("%d\n", *p);
    printf("%p\n", p);
}