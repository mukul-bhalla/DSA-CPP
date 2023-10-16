#include <iostream>
using namespace std;
int sum(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return n + sum(n - 1);
}
int sum_iteration(int n)
{
    int sum = 0;
    for (int i = 0; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}
int main()
{
    int r = 8;
    cout << sum(r);           // RECURSION
    cout << sum_iteration(r); // ITERATION
    cout << r * (r + 1) / 2;  // FORMULA - RECOMMENDED
    return 0;
}