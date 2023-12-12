#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void Display(struct Array *arr)
{
    int i;
    for (i = 0; i <= arr->length - 1; i++)
    {
        cout << arr->A[i] << " ";
    }
    cout << endl;
}
void insertion(struct Array *a, int key)
{
    int i;
    if (a->length < a->size)
    {
        for (i = a->length - 1; key <= a->A[i]; i--)
        {
            a->A[i + 1] = a->A[i];
        }
        a->A[i + 1] = key;
    }
}
int is_sorted(struct Array a)
{
    int i;
    for (i = 0; i < a.length - 1; i++)
    {
        if (a.A[i] > a.A[i + 1])
        {
            return 0;
        }
    }
    return 1;
}
void swap(int *x, int *y)
{
    *x = *x + *y;
    *y = *x - *y;
    *x = *x - *y;
}
void ReArrange(struct Array *a)
{
    int i = 0, j = a->length - 1;
    while (i < j)
    {
        while (a->A[i] < 0)
            i++;
        while (a->A[j] > 0)
            j--;
        if (i < j)
            swap(&a->A[i], &a->A[j]);
    }
}
int main()
{
    struct Array arr = {{1, -2, -9, 11, -21, 200}, 10, 6};
    // insertion(&arr, 12);
    // cout << is_sorted(arr) << endl;
    ReArrange(&arr);
    Display(&arr);

    return 0;
}