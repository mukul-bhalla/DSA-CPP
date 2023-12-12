#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
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
void reverse2(struct Array *a)
{
    int i, j;
    for (i = 0, j = a->length - 1; i < j; i++, j--)
    {
        swap(&a->A[i], &a->A[j]);
    }
}
void Display(struct Array *arr)
{
    int i;
    for (i = 0; i <= arr->length - 1; i++)
    {
        cout << arr->A[i] << " ";
    }
    cout << endl;
}
void LShift(struct Array *a)
{
    int i;
    for (i = 0; i <= a->length - 2; i++)
    {
        a->A[i] = a->A[i + 1];
    }
    a->A[i] = 0;
}
void LRotate(struct Array *a)
{
    int i, temp;
    temp = a->A[0];
    for (i = 0; i <= a->length - 2; i++)
    {
        a->A[i] = a->A[i + 1];
    }
    a->A[i] = temp;
}
void RShift(struct Array *a)
{
    int i;
    for (i = a->length - 1; i > 0; i--)
    {
        a->A[i] = a->A[i - 1];
    }
    a->A[0] = 0;
}
void RRotate(struct Array *a)
{
    int i, temp;
    temp = a->A[a->length - 1];
    for (i = a->length - 1; i > 0; i--)
    {
        a->A[i] = a->A[i - 1];
    }
    a->A[0] = temp;
}
int main()
{
    struct Array arr;
    int i;
    arr.A = new int[10];
    arr.size = 10;
    arr.length = 6;
    arr.A[0] = 1;
    arr.A[1] = 3;
    arr.A[2] = 4;
    arr.A[3] = 5;
    arr.A[4] = 9;
    arr.A[5] = 10;

    // LRotate(&arr);
    // LShift(&arr);
    // RRotate(&arr);
    // RShift(&arr);
    // reverse2(&arr);
    // reverse1(&arr);
    // Display(&arr);
    Display(&arr);

    return 0;
}