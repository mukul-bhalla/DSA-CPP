#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
void reverse1(struct Array *a)
{
    int *temp, i, j;
    temp = new int[a->length];
    for (i = a->length - 1, j = 0; i >= 0, j <= a->length - 1; i--, j++)
    {
        temp[j] = a->A[i];
    }
    for (i = 0; i <= a->length - 1; i++)
    {
        a->A[i] = temp[i];
    }
}
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void reverse2(struct Array *a)
{
    int i, j;
    for (i = 0, j = a->length - 1; i <= a->length - 1, j >= 0; i++, j--)
    {
        swap(&a->A[i], &a->A[j]);
    }
}
int main()
{
    struct Array arr;
    int i;
    arr.A = new int[10];
    arr.size = 10;
    arr.length = 5;
    arr.A[0] = 1;
    arr.A[1] = 3;
    arr.A[2] = 4;
    arr.A[3] = 5;
    arr.A[4] = 9;

    for (i = 0; i <= arr.length - 1; i++)
    {
        cout << arr.A[i] << " ";
    }
    cout << endl;
    reverse2(&arr);
    for (i = 0; i <= arr.length - 1; i++)
    {
        cout << arr.A[i] << " ";
    }

    return 0;
}