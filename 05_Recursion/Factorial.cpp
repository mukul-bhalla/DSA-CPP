#include <iostream>
using namespace std;
int fact(int m)
{
    if (m < 1)
        return 1;
    return m * fact(m - 1);
}
int fact_iterative(int n)
{
    int s = 1, i;
    for (i = 1; i <= n; i++)
    {
        s *= i;
    }
    return s;
}
int main()
{
    int r = 5;
    cout << fact(5);
    cout << fact_iterative(5);
    return 0;
}