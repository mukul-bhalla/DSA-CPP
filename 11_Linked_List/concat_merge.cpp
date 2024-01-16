#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;
void create2(int A[], int n)
{
    int i;
    struct Node *last, *t;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create1(int A[], int n)
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

void concat(struct Node *p, struct Node *q)
{
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = q;
}
void merge(struct Node *p, struct Node *q)
{
    struct Node *last;
    if (p->data < q->data)
    {
        first = p;
        p = p->next;
    }
    else
    {
        first = q;
        q = q->next;
    }
    last = first;
    while (p != NULL && q != NULL)
    {
        if (p->data <= q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
        }
    }
    while (p != NULL)
    {
        last->next = p;
        last = p;
        p = p->next;
    }
    while (q != NULL)
    {
        last->next = q;
        last = q;
        q = q->next;
    }
}
int main()
{
    int A[] = {10, 30, 50, 70, 90};
    int B[] = {20, 40, 60, 80};
    create1(A, 5);
    create2(B, 4);
    merge(first, second);
    Display(first);
    return 0;
}