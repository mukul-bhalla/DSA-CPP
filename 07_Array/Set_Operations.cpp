#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
void Union(struct Array *a, struct Array *b, struct Array *c)
{
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
        {

            c->A[k++] = a->A[i++];
            c->length++;
        }
        else if (a->A[i] > b->A[j])
        {

            c->A[k++] = b->A[j++];
            c->length++;
        }
        else
        {
            c->A[k++] = a->A[i++];
            j++;
            c->length++;
        }
    }
    for (; i < a->length; i++)
    {
        c->A[k++] = a->A[i];
        c->length++;
    }
    for (; j < b->length; j++)
    {
        c->A[k++] = b->A[j];
        c->length++;
    }
}
void Difference(struct Array *a, struct Array *b, struct Array *c)
{
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
        {

            c->A[k++] = a->A[i++];
            c->length++;
        }
        else if (a->A[i] > b->A[j])
        {

            j++;
        }
        else
        {
            j++;
            i++;
        }
    }
    for (; i < a->length; i++)
    {
        c->A[k++] = a->A[i];
        c->length++;
    }
}
void Intersection(struct Array *a, struct Array *b, struct Array *c)
{
    int i = 0, j = 0, k = 0;
    while (i < a->length && j < b->length)
    {
        if (a->A[i] < b->A[j])
            i++;
        else if (a->A[i] > b->A[j])
            j++;
        else
        {
            c->A[k++] = a->A[i++];
            j++;
            c->length++;
        }
    }
}

int main()
{
    struct Array a = {{2, 6, 10, 15, 25}, 10, 5}, b = {{3, 6, 7, 15, 20}, 10, 5}, c;
    int i;
    c.size = 10;
    c.length = 0;

    // Union(&a, &b, &c);
    // Intersection(&a, &b, &c);
    // Difference(&a, &b, &c);

        for (i = 0; i < c.length; i++)
    {
        cout << c.A[i] << " ";
    }
    return 0;
}