#include<iostream>
#include<stdlib.h>
using namespace std;
struct Rectangle
{
    int length;
    int breadth;
};

int main()
{
    // Rectangle r = {10,5};
    // cout<<r.breadth<<endl<<r.length<<endl;
    // Rectangle * p = &r;
    // cout<<p->breadth<<endl<<p->length<<endl;

    Rectangle * p;
    p = new struct Rectangle ;
    p->length=5;
    p->breadth=5;
    cout<<p->breadth<<endl<<p->length<<endl;

    
    return 0;
}