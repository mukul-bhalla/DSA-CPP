#include <iostream>
using namespace std;
class Rectangle
{
    int length;
    int breadth;

public:
    Rectangle(int l, int b);
    int area();
    void changel(int l);
};
Rectangle::Rectangle(int l, int b)
{
    length = l;
    breadth = b;
}
int Rectangle::area()
{
    return length * breadth;
}
void Rectangle::changel(int l)
{
    length = l;
}

int main()
{
    Rectangle obj1(3, 4);
    cout << obj1.area() << endl;
    obj1.changel(5);
    cout << obj1.area() << endl;
    return 0;
}