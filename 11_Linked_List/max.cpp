#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void Display(struct Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int max(struct Node *p)
{
    int m = INT32_MIN;
    while (p != NULL)
    {
        if (p->data > m)
            m = p->data;
        p = p->next;
    }
    return m;
}
int min(struct Node *p)
{
    int m = INT32_MAX;
    while (p != NULL)
    {
        if (p->data < m)
            m = p->data;
        p = p->next;
    }
    return m;
}

int Rmax(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT32_MIN;
    x = Rmax(p->next);
    if (p->data > x)
    {
        return p->data;
    }
    else
    {
        return x;
    }
}
int Rmin(struct Node *p)
{
    int x = 0;
    if (p == NULL)
        return INT32_MAX;
    x = Rmin(p->next);
    if (p->data < x)
    {
        return p->data;
    }
    else
    {
        return x;
    }
}
int main()
{
    int A[] = {3, 5, 7, 10, 15};
    create(A, 5);
    // Display(first);
    cout << max(first) << endl;
    cout << min(first) << endl;
    cout << Rmax(first) << endl;
    cout << Rmin(first) << endl;

    return 0;
}