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

struct Sparse *add(struct Sparse *s1, struct Sparse *s2)
{
    struct Sparse *sum;
    sum = new Sparse;
    sum->e = new Element[s1->num + s2->num];

    // if (s1->m != s2->m || s1->n != s2->n)
    // {
    //     return 0;
    // }
    int i = 0, j = 0, k = 0;
    while (i < s1->num && j < s2->num)
    {
        if (s1->e[i].i < s2->e[j].i)
            sum->e[k++] = s1->e[i++];
        else if (s1->e[i].i > s2->e[j].i)
            sum->e[k++] = s2->e[j++];
        else
        {
            if (s1->e[i].j < s2->e[j].j)
                sum->e[k++] = s1->e[i++];
            else if (s1->e[i].j > s2->e[j].j)
                sum->e[k++] = s2->e[j++];
            else
            {
                sum->e[k] = s1->e[i++];
                sum->e[k++].x += s2->e[j++].x;
            }
        }
    }
    for (; i < s1->num; i++)
    {
        sum->e[k++] = s1->e[i];
    }
    for (; j < s2->num; j++)
    {
        sum->e[k++] = s2->e[j];
    }
    sum->m = s1->m;
    sum->n = s1->n;
    sum->num = k;
    return sum;
}

int main()
{
    struct Sparse s1, s2, *s3;
    create(&s1);
    create(&s2);
    // display(s);
    // display(add(&s1, &s2));
    s3 = add(&s1, &s2);
    display(*s3);
    return 0;
}