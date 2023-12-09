#include <iostream>
using namespace std;
int main()
{
    int i, j;
    int A[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    cout << A[0][1] << endl;

    int *B[3];
    B[0] = new int[4];
    B[1] = new int[4];
    B[2] = new int[4];
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cin >> B[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 4; j++)
        {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }

    int **C;
    C = new int *[3];
    C[0] = new int[3];
    C[1] = new int[3];
    C[2] = new int[3];

    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cin >> C[i][j];
        }
    }
    for (i = 0; i < 3; i++)
    {
        for (j = 0; j < 3; j++)
        {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}