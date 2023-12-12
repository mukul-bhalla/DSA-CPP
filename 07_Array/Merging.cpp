#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void merge(struct Array *a, struct Array *b, struct Array *c)
{
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            c->A[k++] = a->A[i++];
        else
            c->A[k++] = b->A[j++];
    }
    for (; i < a->length; i++)
    {
        c->A[k++] = a->A[i];
    }
    for (; j < b->length; j++)
    {
        c->A[k++] = b->A[j];
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
int main()
{
    struct Array a, b, c;
    a = {{3, 4, 5, 12, 45, 67}, 10, 6};
    b = {{2, 6, 8, 11, 29}, 10, 5};
    c.size = a.length + b.length;
    c.length = a.length + b.length;
    merge(&a, &b, &c);
    Display(&c);
    return 0;
}