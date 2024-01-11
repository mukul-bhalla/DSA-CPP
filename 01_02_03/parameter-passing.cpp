#include <iostream>
using namespace std;
int swap(int &x, int y)
{
    x = x + y;
    y = x - y;
    x = x - y;
}
int main()
{
    int a = 10, b = 15;
    cout << a << " " << b << endl;
    swap(a, b);
    cout
        << a << " " << b << endl;
    return 0;
}