#include <iostream>
using namespace std;

void Insert(int H[], int n)
{
    int i = n, temp = H[i];

    while (i > 1 && temp > H[i / 2])
    {
        H[i] = H[i / 2];
        i = i / 2;
    }
    H[i] = temp;
}

int Delete(int H[], int n)
{
    int i, j, x, val;
    val = H[1];
    x = H[n];
    H[1] = H[n];
    i = 1;
    j = i * 2;
    while (j < n - 1)
    {
        if (H[j + 1] > H[j])
            j = j + 1;
        if (H[i] < H[j])
        {
            H[i] = H[i] + H[j];
            H[j] = H[i] - H[j];
            H[i] = H[i] - H[j];
            i = j;
            j = i * 2;
        }
        else
        {
            break;
        }
    }
    H[n] = val;
    return val;
}
int main()
{
    int i;
    int H[] = {0, 10, 20, 30, 25, 5, 40, 35};
    for (i = 1; i <= 7; i++)
    {
        Insert(H, i);
    }

    for (i = 7; i > 1; i--)
    {

        Delete(H, i);
    }
    for (i = 1; i <= 7; i++)
    {
        cout << H[i] << ' ';
    }
    return 0;
}