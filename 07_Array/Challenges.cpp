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
        A[0] = 2;
        A[1] = 5;
        A[2] = 9;
        A[3] = 11;
        A[4] = 12;
        A[5] = 13;
        A[6] = 14;
        A[7] = 15;
        A[8] = 16;
        A[9] = 18;
    }
    int MissingElement1();
    void MissingElementMore();
    void MissingElementMore2();
    void FindDuplicates();
    void FindDuplicateCount();
    void FindDuplicateCount2();
    void FindPair(int k);
    void FindPairBetter(int k);
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
void Array::FindDuplicates()
{
    int lastDuplicate = 0, i;
    for (i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1] && A[i] != lastDuplicate)
        {
            cout << A[i] << " ";
            lastDuplicate = A[i];
        }
    }
}
void Array::FindDuplicateCount()
{
    int i, j;
    for (i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1])
        {
            j = i + 1;
            while (A[j] == A[i])
                j++;
            cout << A[i] << " Occurs " << j - i << "times";
            i = j - 1;
        }
    }
}
void Array::FindDuplicateCount2()
{
    int *H = new int[19]();
    int i, j;
    for (i = 0; i < length; i++)
    {
        if (A[i] == A[i + 1])
        {
            H[A[i]] = 1;
            j = i + 1;
            while (A[j] == A[i])
            {
                j++;
                H[A[i]]++;
            }
            i = j - 1;
        }
    }
    for (i = 0; i < 19; i++)
    {
        if (H[i] > 1)
        {

            cout << i << " occurs " << H[i] << "times";
        }
    }
    delete[] H;
}
void Array::FindPair(int k)
{
    int i, j;
    for (i = 0; i < length - 1; i++)
    {
        for (j = i + 1; j < length; j++)
        {
            if (A[i] + A[j] == k)
            {
                cout << A[i] << " " << A[j] << endl;
            }
        }
    }
}
void Array::FindPairBetter(int k)
{
    int *H = new int[20]();

    int i, j;
    for (i = 0; i < length; i++)
    {
        if (H[k - A[i]] != 0)
            cout << A[i] << k - A[i] << endl;
        H[A[i]]++;
    }
}
int main()
{
    Array obj;
    // cout << obj.MissingElement1() << endl;
    // obj.MissingElementMore();
    // obj.MissingElementMore2();
    // obj.FindDuplicateCount();
    // obj.FindDuplicateCount2();
    // obj.FindPair(20);
    // obj.FindPairBetter(20);
    return 0;
}