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

void Merge(int A[], int l, int mid, int h)
{
    int i = l, j = mid + 1, k = l;
    int B[100];
    while (i <= mid && j <= h)
    {
        if (A[i] < A[j])
            B[k++] = A[i++];
        else
            B[k++] = A[j++];
    }
    for (; i <= mid; i++)
    {
        B[k++] = A[i++];
    }
    for (; j <= h; j++)
    {
        B[k++] = A[j++];
    }

    for (i = 0; i <= h; i++)
    {
        A[i] = B[i];
    }
}

void ImergeSort(int A[], int n)
{
    int i, p, l, mid, h;

    for (p = 2; p <= n; p = p * 2)
    { // FOR PARSES
        for (i = 0; i + p - 1 <= n; i = i + p)
        // For low mid and high
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            Merge(A, l, mid, h);
        }
    }
    if (p / 2 < n)
    // For Odd elements
    {
        Merge(A, 0, p / 2 - 1, n - 1);
    }
}

int main()
{
    int A[] = {3, 7, 9, 10, 6, 5, 12, 4, 11, 2}, n = 10;
    for (int x : A)
    {
        cout << x << " ";
    }
    cout << endl;

    // bubbleSort(A, n);

    // insertionSort(A, n);

    // selectionSort(A, n);

    // quickSort(A, 0, 10);

    // ImergeSort(A, n);

        for (int x : A)
    {
        cout << x << " ";
    }
    return 0;
}