#include <iostream>
using namespace std;
void fun(int n)
{
    if (n > 0)
    {
        fun(n - 1); // OUTPUT :- in ascening order
        cout << n << endl;
        // If function called here then in descending order
    }
}
int main()
{
    int x = 5;
    fun(x);
    return 0;
}