#include <iostream>
#include <algorithm>
using namespace std;
class Array
{
private:
    int *A;
    int length, size;

public:
    Array()
    {
        A = new int[10];
        length = 10;
        size = 10;
        A[0] = 7;
        A[1] = 8;
        A[2] = 9;
        A[3] = 11;
        A[4] = 12;
        A[5] = 15;
        A[6] = 16;
        A[7] = 17;
        A[8] = 18;
        A[9] = 19;
    }
    int MissingElement1();
    void MissingElementMore();
    void MissingElementMore2();
};
int Array ::MissingElement1()
{
    int num = length - 1;
    int high = A[num], low = A[0], i;
    for (i = 1; i < length; i++)
    {
        if (A[i] - i != low)
        {
            return i + low;
        }
    }
    return 0;
}
void Array::MissingElementMore()
{
    int num = length - 1;
    int diff = A[0] - 0;
    int i;
    for (i = 1; i < length; i++)
    {
        if (A[i] - i != diff)
        {
            while (diff < A[i] - i)
            {
                cout << i + diff << " ";
                diff++;
            }
        }
    }
}
void Array::MissingElementMore2()
{
    int MAX = 19, i;
    int *H = new int[MAX];
    for (i = 0; i < length; i++)
    {
        H[A[i]] = 0;
    }
    for (i = 7; i <= 19; i++)
    {
        if (H[i] != 0)
        {
            cout << i << " ";
        }
    }
    delete[] H;
}
int main()
{
    Array obj;
    cout << obj.MissingElement1() << endl;
    obj.MissingElementMore();
    obj.MissingElementMore2();

    return 0;
}