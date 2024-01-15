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
int deleteNode(struct Node *p, int pos)
{
    struct Node *q = NULL;
    int i, x = -1;
    if (pos == 1)
    {
        p = first;
        first = first->next;
        x = p->data;

        delete p;
    }
    else
    {
        for (i = 0; i < pos - 1 && p; i++)
        {
            q = p;
            p = p->next;
        }
        if (p)
        {
            q->next = p->next;
            x = p->data;
            delete p;
        }
    }
    return x;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    cout << deleteNode(first, 1);
    Display(first);
    return 0;
}