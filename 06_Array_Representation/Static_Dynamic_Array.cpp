#include <iostream>
using namespace std;
int main()
{
    int A[10] = {2, 4, 6, 8, 10}, i;
    int *p;
    p = new int[5];
    p[0] = 3;
    p[1] = 5;
    p[2] = 7;
    p[3] = 9;
    p[4] = 11;
    for (i = 0; i < 5; i++)
    {
        cout << A[i] << endl;
    }
    for (i = 0; i < 5; i++)
    {
        cout << *(p + i) << endl;
    }
    return 0;
}