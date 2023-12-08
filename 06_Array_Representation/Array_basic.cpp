#include <iostream>
using namespace std;
int main()
{
    int a[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        cout << i[a] << endl;
        cout << int(&a[i]) << endl;
    }
    return 0;
}