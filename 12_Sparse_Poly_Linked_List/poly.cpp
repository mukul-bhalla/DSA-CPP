#include <iostream>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly1 = NULL, *poly2 = NULL;
void Create1()
{
    int num, coeff, exp, i;
    struct Node *p = poly1, *last = NULL;
    cout << "Enter number of terms of polynomial :";
    cin >> num;
    for (i = 0; i < num; i++)
    {
        cout << "Enter coeff and exp of term " << i + 1 << " : ";
        cin >> coeff >> exp;
        if (poly1 == NULL)
        {
            poly1 = new Node;
            poly1->coeff = coeff;
            poly1->exp = exp;
            poly1->next = NULL;
            last = poly1;
        }
        else
        {
            p = new Node;
            p->coeff = coeff;
            p->exp = exp;
            p->next = NULL;
            last->next = p;
            last = p;
        }
    }
}
void Create2()
{
    int num, coeff, exp, i;
    struct Node *p = poly2, *last = NULL;
    cout << "Enter number of terms of polynomial :";
    cin >> num;
    for (i = 0; i < num; i++)
    {
        cout << "Enter coeff and exp of term " << i + 1 << " : ";
        cin >> coeff >> exp;
        if (poly2 == NULL)
        {
            poly2 = new Node;
            poly2->coeff = coeff;
            poly2->exp = exp;
            poly2->next = NULL;
            last = poly2;
        }
        else
        {
            p = new Node;
            p->coeff = coeff;
            p->exp = exp;
            p->next = NULL;
            last->next = p;
            last = p;
        }
    }
}
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->coeff << " x^" << p->exp << endl;
        p = p->next;
    }
}
int pow(int x, int e)
{
    int temp = e, res = 1, i;
    if (e == 0)
    {
        return 1;
    }
    if (e == 1)
        return x;
    for (i = 1; i <= temp; i++)
    {
        res *= x;
    }
    return res;
}
int Evaluate(struct Node *p, int x)
{
    double ans = 0.0;
    while (p)
    {
        ans += p->coeff * (pow(x, p->exp));
        p = p->next;
    }
    return ans;
}
struct Node *Add(struct Node *p1, struct Node *p2)
{
    struct Node *ans = NULL;
    while (p1 && p2)
    {
        if (p1->exp == p2->exp)
        {
            p1->coeff += p2->exp;
            p1 = p1->next;
            p2->next;
        }
        else if (p1->exp < p2->exp)
        {
        }
    }
}
int main()
{
    Create1();
    Display(poly1);
    cout << endl;
    Create2();
    Display(poly2);
    // cout << Evaluate(poly1, 3);
    return 0;
}