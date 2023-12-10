#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};

void Append(struct Array *a)
{
    int element;
    cin >> element;
    if (a->length < a->size)
    {
        a->A[a->length] = element;
        a->length++;
    }
    else
    {
        cout << "Array is full !!!" << endl;
    }
}

void Insert(struct Array *a)
{
    int idx, e, i;
    cout << "Enter element to be inserted :";
    cin >> e;
    cout << "Enter the index :";
    cin >> idx;
    if (idx > a->size || a->length == a->size)
    {
        cout << "Cannot Insert !!";
    }
    else
    {
        for (i = a->length; i > idx; i--)
        {
            a->A[i] = a->A[i - 1];
        }
        a->A[idx] = e;
        a->length++;
    }
}

int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};
    int i;
    Insert(&arr);
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    return 0;
}