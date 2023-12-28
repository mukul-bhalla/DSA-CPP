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
        n = 2;
        A = new int[n]();
    }
    Matrix(int n)
    {
        this->n = n;
        A = new int[(n * (n - 1)) / 2]();
    }
    void set(int i, int j, int x);
    int get(int i, int j);
    void display();
    ~Matrix()
    {
        delete[] A;
        cout << "Memory released !";
    }
};
void Matrix::set(int i, int j, int x)
{
    if (i <= j)
    {
        A[(j * (j - 1)) / 2 + i - 1] = x;
    }
    else
    {
        cout << "Cannot be altered !";
    }
}
int Matrix::get(int i, int j)
{
    return A[(j * (j - 1)) / 2 + i - 1];
}
void Matrix::display()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i <= j)

                cout << A[(j * (j + 1)) / 2 + i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main()
{
    Matrix M(3);
    M.set(1, 1, 1);
    M.set(1, 2, 2);
    M.set(1, 3, 3);
    M.set(2, 2, 4);
    M.set(2, 3, 5);
    M.set(3, 3, 6);
    M.display();
    return 0;
}