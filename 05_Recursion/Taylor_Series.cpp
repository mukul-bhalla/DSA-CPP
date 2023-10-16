#include <iostream>
#include <math.h>
using namespace std;
double taylor(int x, int n)
{
    static double num = 1, den = 1;
    if (n == 0)
    {
        return 1;
    }
    double r = taylor(x, n - 1);
    num = num * x;
    den = den * n;
    return r + num / den;
}
int main()
{
    int r = 5;
    cout << taylor(1, 10);
    return 0;
}