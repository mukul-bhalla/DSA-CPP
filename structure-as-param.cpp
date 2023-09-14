#include <iostream>
#include <stdlib.h>
using namespace std;

struct Rectangle
{
    int length;
    int breadth;
    int number[5];
};
struct Rectangle *fun()
{
    struct Rectangle *p;
    p = new Rectangle;
    p->length = 7;
    p->breadth = 2;
    for (int i = 0; i < 5; i++)
    {
        p->number[i] = i + 1;
    }

    return p;
}
int main()
{
    struct Rectangle *ptr;
    ptr = fun();
    cout << ptr->breadth << ptr->length;
    for (int i = 0; i < 5; i++)
    {
        cout << ptr->number[i];
    }
    return 0;
}