#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n;

public:
    Matrix()
    {
        A = new int[2]();
    }
    Matrix(int n)
    {
        this->n = (n * (n - 2)) / 2;
        A = new int[this->n]();
    }
    void set(int i, int j, int x);
    int get(int i, int j);
};
void Matrix::set(int i, int j, int x)
{
    if (i >= j)
    {
        A[(i * (i - 1) / 2) + (j - 1)] = x;
    }
    else
    {
        cout << "Cannot be a non-zero value !";
    }
}
int Matrix::get(int i, int j)
{
    if (i < j)
        return 0;
    return A[(i * (i - 1) / 2) + (j - 1)];
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    Matrix M(n);
    M.set(1, 1, 1);
    M.set(2, 1, 2);
    M.set(2, 2, 3);
    M.set(3, 1, 4);
    M.set(3, 2, 5);
    M.set(3, 3, 6);
    M.set(4, 1, 7);
    M.set(4, 2, 8);
    M.set(4, 3, 9);
    M.set(4, 4, 10);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i >= j)
            {
                cout << M.get(i + 1, j + 1) << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }

    return 0;
}