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
    struct Node *last, *t;
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
int count(struct Node *p)
{
    int x = 0;
    while (p != NULL)
    {
        // cout << p->data << " ";
        x++;
        p = p->next;
    }
    return x;
}
void Reverse1(struct Node *p)
{
    int *A = new int[count(first)];
    int i = 0;
    while (p != NULL)
    {
        A[i++] = p->data;
        p = p->next;
    }
    p = first;
    i--;
    while (p != NULL)
    {
        p->data = A[i--];
        p = p->next;
    }
    delete A;
}
void BetterReverse(struct Node *p)
{
    struct Node *q = NULL, *r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r;
    }
    first = q;
}
void RecursiveReverse(struct Node *q, struct Node *p)
{
    if (p != NULL)
    {
        RecursiveReverse(p, p->next);
        p->next = q;
    }
    else
    {
        first = q;
    }
}
int main()
{
    int A[] = {10, 20, 30, 40};
    create(A, 4);
    Display(first);
    cout << endl;
    RecursiveReverse(NULL, first);
    Display(first);

    return 0;
}