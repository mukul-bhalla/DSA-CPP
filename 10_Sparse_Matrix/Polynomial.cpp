#include <iostream>
using namespace std;

class Term
{
public:
    int coeff, exp;
};

class Poly
{
private:
    int num;
    Term *t;

public:
    Poly(int num)
    {
        this->num = num;
        t = new Term[this->num];
    }

    void create()
    {
        int i;
        cout << "Enter :" << endl;
        for (i = 0; i < num; i++)
        {
            cout << "Enter Coefficient And Exponent: ";
            cin >> t[i].coeff >> t[i].exp;
        }
    }
    void display()
    {
        cout << num << endl;
        int i;
        for (i = 0; i < num; i++)
        {
            cout << t[i].coeff << " x^ " << t[i].exp << endl;
        }
    }

    Poly operator+(Poly &p);

    ~Poly()
    {
        delete[] t;
    }
};
Poly Poly::operator+(Poly &p)
{
    int i = 0, j = 0, k = 0;
    Poly *sum = new Poly(num + p.num);

    while (i < num && j < p.num)
    {
        if (t[i].exp > p.t[j].exp)
            sum->t[k++] = t[i++];
        else if (t[i].exp < p.t[j].exp)
            sum->t[k++] = p.t[j++];
        else
        {
            // int temp = k;
            sum->t[k].exp = t[i].exp;
            sum->t[k++].coeff = t[i++].coeff + p.t[j++].coeff;
            // cout << sum->t[temp].coeff;
        }
        cout << k << endl;
    }
    for (; i < num; i++)
    {
        sum->t[k++] = t[i];
    }
    for (; j < p.num; j++)
    {
        sum->t[k++] = p.t[j];
    }
    sum->num = k;
    return *sum;
}
int main()
{
    Poly p1(3);
    p1.create();
    // p1.display();
    // p1.display();
    Poly p2(5);
    p2.create();
    // p2.display();

    Poly p3 = p1 + p2;
    p3.display();
    return 0;
}