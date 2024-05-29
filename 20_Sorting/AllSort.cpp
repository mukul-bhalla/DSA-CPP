#include <iostream>
using namespace std;
void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}
void bubbleSort(int A[], int n)
{
    int i, j, flag;
    for (i = 0; i < n - 1; i++)
    {
        flag = 0;
        for (j = 0; j < n - i - 1; j++)
        {
            if (A[j] > A[j + 1])
            {
                swap(A[j], A[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void insertionSort(int A[], int n)
{
    int i, j, x;
    for (i = 1; i < n; i++)
    {
        j = i - 1;
        x = A[i];
        while (j > -1 && A[j] > x)
        {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = x;
    }
}

void selectionSort(int A[], int n)
{
    int i, j, k;
    for (i = 0; i < n - 1; i++)
    {
        for (j = k = i; j < n; j++)
        {
            if (A[j] < A[k])
            {
                k = j;
            }
            swap(A[i], A[k]);
        }
    }
}

int Partition(int A[], int l, int h)
{
    int pivot = A[l];
    int i = l, j = h;
    do
    {
        do
        {
            i++;
        } while (A[i] <= pivot);
        do
        {
            j--;
        } while (A[j] > pivot);
        if (i < j)
            swap(A[i], A[j]);
    } while (i < j);
    swap(A[l], A[j]);
    return j;
}

void quickSort(int A[], int l, int h)
{
    int middle;
    if (l < h)
    {
        middle = Partition(A, l, h);
        quickSort(A, l, middle);
        quickSort(A, middle + 1, h);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2, INT32_MAX}, n = 11;
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;

    // bubbleSort(A, n);

    // insertionSort(A, n);

    // selectionSort(A, n);

    // quickSort(A, 0, 10);

        for (int x : A)
    {
        cout << x << " ";
    }
    return 0;
}