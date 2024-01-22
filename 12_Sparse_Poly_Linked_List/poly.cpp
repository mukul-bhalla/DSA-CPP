#include <iostream>
using namespace std;
struct Node
{
    int coeff;
    int exp;
    struct Node *next;
} *poly = NULL;
void Create()
{
    int num, coeff, exp, i;
    struct Node *p = poly, *last = NULL;
    cout << "Enter number of terms of polynomial :";
    cin >> num;
    for (i = 0; i < num; i++)
    {
        cout << "Enter coeff and exp of term " << i + 1 << " : ";
        cin >> coeff >> exp;
        if (poly == NULL)
        {
            poly = new Node;
            poly->coeff = coeff;
            poly->exp = exp;
            poly->next = NULL;
            last = poly;
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
int main()
{
    Create();
    // Display(poly);
    cout << Evaluate(poly, 3);
    return 0;
}