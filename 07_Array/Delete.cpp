#include <iostream>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};
int Delete(struct Array *a)
{
    int idx, i, del;
    cout << "Enter element to be deleted :";
    cin >> idx;
    if (idx >= 0 && idx < a->length)
    {

        del = a->A[idx];
        for (i = idx; i < a->length - 1; i++)
        {
            a->A[i] = a->A[i + 1];
        }
        a->length--;

        return del;
    }
    else
    {
        return -1;
    }
}
int main()
{
    struct Array arr = {{1, 2, 3, 4, 5, 6}, 10, 6};
    int i;
    cout << Delete(&arr) << endl;
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    return 0;
}