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
    t = new Node;
    first = t;
    last = first;
    t->data = A[0];
    t->next = NULL;
    for (i = 1; i < n; i++)
    {
        struct Node *n = new Node;
        n->data = A[i];
        last->next = n;
        last = n;
        n->next = NULL;
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
void InsertAtLast(struct Node *p, int x)
{
    struct Node *t = new Node;
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p->next != NULL)
        {
            p = p->next;
        }
        p->next = t;
    }
}
void SortedInsert(struct Node *p, int key)
{
    struct Node *t, *q = NULL;
    t = new Node;
    t->data = key;
    t->next = NULL;
    if (first == NULL)
    {
        first = t;
    }
    else
    {
        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if (p == first)
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
    }
}
int main()
{
    int A[] = {2, 4, 6, 8, 10, 11, 12};
    create(A, 7);
    // SortedInsert(first, 1);
    InsertAtLast(first, 2);
    Display(first);
    return 0;
}