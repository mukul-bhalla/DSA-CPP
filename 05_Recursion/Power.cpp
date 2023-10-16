#include <iostream>
using namespace std;
int power(int m, int n)
{
    if (n == 0)
        return 1;
    return m * power(m, n - 1);
}
int power_effective(int m, int n) // REDUCED STEPS
{
    if (n == 0)
        return 1;
    if (n % 2 == 0)
        return power_effective(m * m, n / 2);
    else
        return m * power_effective(m * m, n / 2);
}
int main()
{
    int m = 5, n = 4;
    cout << power(m, n);
    m = 2, n = 9;
    cout << power(2, 9);
    cout << power_effective(2, 9);
    return 0;
}