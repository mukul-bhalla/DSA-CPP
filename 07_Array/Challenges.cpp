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
        A = new int[5];
        length = 5;
        size = 5;
        A[0] = 8;
        A[1] = 9;
        A[2] = 10;
        A[3] = 12;
        A[4] = 13;
    }
    int MissingElement1();
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
int main()
{
    Array obj;
    cout << obj.MissingElement1();

    return 0;
}