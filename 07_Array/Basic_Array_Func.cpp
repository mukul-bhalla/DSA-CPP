#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};
int get(struct Array *a, int index)
{
    if (index >= 0 && index < a->length)
        return a->A[index];
    else
        return -1;
}
void set(struct Array *a, int index, int val)
{
    if (index >= 0 && index < a->length)
        a->A[index] = val;
}
int max(struct Array *a)
{
    int max = a->A[0], i;
    for (i = 1; i < a->length; i++)
    {
        if (a->A[i] > max)
            max = a->A[i];
    }
    return max;
}
int min(struct Array *a)
{
    int min = a->A[0], i;
    for (i = 1; i < a->length; i++)
    {
        if (a->A[i] < min)
            min = a->A[i];
    }
    return min;
}
int sum(struct Array *a)
{
    int sum = 0, i;
    for (i = 0; i < a->length; i++)
    {
        sum += a->A[i];
    }
    return sum;
}
float avg(struct Array *a)
{
    int s = sum(a);
    return (float)s / a->length;
}
int main()
{
    struct Array arr;
    arr.A = new int[10];
    arr.size = 10;
    arr.length = 5;
    arr.A[0] = 1;
    arr.A[1] = 2;
    arr.A[2] = 3;
    arr.A[3] = 4;
    arr.A[4] = 5;
    cout << get(&arr, 4);
    set(&arr, 4, 10);
    cout << get(&arr, 4);
    cout << max(&arr);
    cout << min(&arr);
    cout << sum(&arr);
    cout << avg(&arr);
    return 0;
}