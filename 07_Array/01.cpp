#include <iostream>
using namespace std;
struct Array
{
    int *A;
    int size;
    int length;
};

int main()
{
    struct Array arr;
    cout << "Enter array size :";
    cin >> arr.size;
    arr.A = new int[arr.size];
    arr.length = 0;
    int n, i;
    cout << "Enter array length :";
    cin >> n;
    arr.length = n;
    cout << "Enter all elements";
    for (i = 0; i < n; i++)
    {
        cin >> arr.A[i];
    }
    for (i = 0; i < arr.length; i++)
    {
        cout << arr.A[i] << " ";
    }
    return 0;
}