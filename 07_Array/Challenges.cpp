#include <iostream>
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
int main()
{
    Array obj;
    cout << obj.MissingElement1() << endl;
    obj.MissingElementMore();

    return 0;
}