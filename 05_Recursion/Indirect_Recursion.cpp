#include <iostream>
using namespace std;

// Cyclic Function Calling Each Other
void funA(int n);

void funB(int n);

int main()
{
    funB(20);
    return 0;
}

void funA(int n)
{
    if (n > 0)
    {
        cout << n;
        funB(n - 1);
    }
}
void funB(int n)
{
    if (n > 1)
    {
        cout << n;
        funA(n / 2);
    }
}