#include <iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
void create(int A[], int n)
{
    struct Node *t, *last;
    int i;
    first = new Node;
    first->prev = NULL;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->prev = last;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int count(struct Node *p)
{
    int x = 0;
    while (p)
    {
        x++;
        p = p->next;
    }
    return x;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(first))
        return;
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->prev = NULL;
        t->next = first;
        first->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->next = p->next;
        t->prev = p;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int main()
{
    int A[] = {3, 4, 6, 7, 9};
    create(A, 5);
    Insert(first, 5, 1);
    Display(first);
    // cout << count(first);
    return 0;
}