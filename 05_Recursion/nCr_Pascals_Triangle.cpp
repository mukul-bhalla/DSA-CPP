#include <iostream>
using namespace std;
int fact(int n)
{
    if (n <= 1)
        return 1;
    else
        return n * fact(n - 1);
}
int C(int n, int r)
{
    int t1, t2, t3;
    t1 = fact(n);
    t2 = fact(r);
    t3 = fact(n - r);
    return t1 / (t2 * t3);
}
int Pascal(int n, int r)
{
    if (n == r || r == 0)
        return 1;
    else
        return Pascal(n - 1, r - 1) + Pascal(n - 1, r);
}
int main()
{
    cout << C(7, 4) << endl;
    cout << Pascal(7, 4);
    return 0;
}