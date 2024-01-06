#include <iostream>
using namespace std;

class Element
{
public:
    int i, j, x;
};

class Sparse
{
private:
    int m, n, num;
    Element *e;

public:
    Sparse(int m, int n, int num)
    {
        this->m = m;
        this->n = n;
        this->num = num;
        e = new Element[this->num];
    }

    void read()
    {
        cout << "Enter number of non zero elements:";
        cin >> num;
        int a;
        for (a = 0; a < num; a++)
        {
            cout << "Enter row column element: ";
            cin >> e[a].i >> e[a].j >> e[a].x;
        }
    }
    void display()
    {
        int i, j, k = 0;
        for (i = 1; i <= m; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if (e[k].i == i && e[k].j == j)
                {
                    cout << e[k++].x << " ";
                }
                else
                {
                    cout << "0 ";
                }
            }
            cout << endl;
        }
    }

    Sparse operator+(Sparse &s);

    ~Sparse()
    {
        delete[] e;
    }
};
Sparse Sparse::operator+(Sparse &s)
{
    int i, j, k;
    // if (m != s.m || n == s.n)
    // {
    //     return NULL;
    // }
    Sparse *sum = new Sparse(m, n, num + s.num);
    i = j = k = 0;
    while (i < num && j < s.num)
    {
        if (e[i].i < s.e[j].i)
            sum->e[k++] = e[i++];
        else if (e[i].i > s.e[j].i)
            sum->e[k++] = s.e[j++];
        else
        {
            if (e[i].j < s.e[j].j)
                sum->e[k++] = e[i++];
            else if (e[i].j > s.e[j].j)
                sum->e[k++] = s.e[j++];
            else
            {
                sum->e[k] = e[i++];
                sum->e[k++].x += s.e[j++].x;
            }
        }
    }
    for (; i < num; i++)
    {
        sum->e[k++] = e[i];
    }
    for (; j < num; j++)
    {
        sum->e[k++] = e[j];
    }
    sum->num = k;
    return *sum;
}
int main()
{
    Sparse s(5, 5, 5);
    s.read();
    // s.display();
    Sparse s1(5, 5, 5);
    s1.read();

    Sparse sum = s + s1;
    sum.display();
    return 0;
}