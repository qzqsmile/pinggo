#include<iostream>
#include<stdlib.h>
#include<typeinfo>

using std::cout;
using std::endl;

// typedef struct list *list;

struct list{
    int a; 
};

int main(void)
{
    struct list a;
    struct list *b;
    b = new list;

    b->a = 1;
    cout << "b is:" << b->a <<endl;
    return 0;
}