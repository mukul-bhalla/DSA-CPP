#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
int LS(struct Array a, int key)
{
    int i;
    for (i = 0; i < a.length; i++)
    {
        if (key == a.A[i])
        {
            return i;
        }
    }
    return -1;
}
int swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
int BetterLS(struct Array *a, int key)
{
    int i;
    for (i = 0; i < a->length; i++)
    {
        if (key == a->A[i])
        {
            swap(a->A[i], a->A[i - 1]);
            return i - 1;
        }
    }
    return -1;
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};
    int i;
    cout << BetterLS(&arr, 3) << endl;
    // cout << BetterLS(&arr, 3) << endl;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    return 0;
}