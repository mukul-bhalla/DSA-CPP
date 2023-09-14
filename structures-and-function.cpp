#include <iostream>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};
void initialize(Rectangle *ptr, int l, int b)
{
    ptr->length = l;
    ptr->breadth = b;
}
int area(Rectangle r1)
{
    return r1.breadth * r1.length;
}
void changel(Rectangle *p, int l)
{
    p->length = l;
}
int main()
{
    Rectangle p;
    initialize(&p, 2, 3);
    cout << area(p);
    changel(&p, 4);
    cout << area(p);
    return 0;
}