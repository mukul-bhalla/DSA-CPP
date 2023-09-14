#include<iostream>
#include<stdlib.h>
using namespace std;
int main()
{
    int a = 10;
    int &r = a;  // Referencing  (For Parameter Passing)
    cout<<a<<endl;
    cout<<r<<endl;
    r++;
    int b = 30;
    r=b;
    
    cout<<a<<endl;

     
}