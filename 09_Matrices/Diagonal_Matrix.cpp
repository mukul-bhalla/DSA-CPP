#include <iostream>
using namespace std;

class Matrix
{
private:
    int *A;
    int n = 0;

public:
    Matrix()
    {
        A = new int[n]();
    }
    Matrix(int n)
    {
        A = new int[n]();
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    ~Matrix()
    {
        delete[] A;
        cout << "Memory released";
    }
};
void Matrix::set(int i, int j, int x)
{
    if (i == j)
    {
        A[i - 1] = x;
    }
    else
    {
        cout << "Cannot be a non-zero value !";
    }
}
int Matrix::get(int i, int j)
{
    if (i != j)
        return 0;
    return A[i - 1];
}
int main()
{
    Matrix M(5);
    M.set(1, 1, 6);
    M.set(2, 2, 8);
    M.set(3, 3, 10);
    M.set(4, 4, 12);
    M.set(5, 5, 14);
    M.set(5, 6, 14);

    cout << M.get(1, 1) << endl;
    cout << M.get(2, 2) << endl;
    cout << M.get(3, 3) << endl;
    cout << M.get(4, 4) << endl;
    cout << M.get(5, 5) << endl;

    return 0;
}