#include <iostream>
using namespace std;
struct Element
{
    int i;
    int j;
    int x;
};
struct Sparse
{
    int m;
    int n;
    int num;
    struct Element *e;
};
void create(struct Sparse *s)
{
    int i;
    cout << "Enter Dimensions :";
    cin >> s->m >> s->n;
    cout << "Enter number of non-zero elements :";
    cin >> s->num;
    s->e = new Element[s->num];
    for (i = 0; i < s->num; i++)
    {
        cout << "Enter row column element :";
        cin >> s->e[i].i >> s->e[i].j >> s->e[i].x;
    }
}
void display(struct Sparse s)
{
    int i, j, k = 0;
    for (i = 1; i <= s.m; i++)
    {
        for (j = 1; j <= s.n; j++)
        {
            if (i == s.e[k].i && j == s.e[k].j)
            {
                cout << s.e[k++].x << " ";
            }
            else
            {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}
int main()
{
    struct Sparse s;
    create(&s);
    display(s);
    return 0;
}