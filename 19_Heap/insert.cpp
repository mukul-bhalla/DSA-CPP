#include <iostream>
using namespace std;
void Insert(int A[], int n, int key)
{
    A[n] = key;

    int i = n;
    if (i % 2 != 0)
    {
        while (key > A[(i - 1) / 2])
        {
            A[i] = A[(i - 1) / 2];
            i = (i - 1) / 2;
        }
        A[i] = key;
    }
    else
    {
        while (key > (((i % 2) != 0) ? A[(i - 1) / 2] : A[(i / 2) - 1]))
        {
            A[i] = ((i % 2) != 0) ? A[(i - 1) / 2] : A[(i / 2) - 1];
            i = ((i % 2) != 0) ? (i - 1) / 2 : (i / 2) - 1;
        }
        A[i] = key;
    }
}
void Display(int A[], int n)
{

    for (int i = 0; i < n; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{

    int *Heap = new int[10]{40, 35, 30, 20, 10, 15, 9, 8};

    int n = 8;
    Display(Heap, n);
    // cout << endl;
    // Insert(Heap, n, 37);
    // Display(Heap, n + 1);
    cout << endl;
    Insert(Heap, n, 36);
    Display(Heap, n + 1);
    return 0;
}