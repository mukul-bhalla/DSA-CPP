#include <iostream>
using namespace std;
int main()
{
    int *p = new int[5];
    int *q = new int[10];
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;
    p[3] = 3;
    p[4] = 4;
    for (int i = 0; i < 5; i++)
    {
        cout << *(p + i) << endl;
    }

    for (int i = 0; i < 5; i++)
    {
        q[i] = p[i];
    }
    p = q;
    for (int i = 0; i < 5; i++)
    {
        cout << p[i] << endl;
    }
    delete[] q;
    q = NULL;

    return 0;
}