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
int count(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count++;
        p = p->next;
    }
    return count;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(p))
    {
        return;
    }
    t = new Node;
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
        {
            p = p->next;
        }
        t->next = p->next;
        p->next = t;
    }
}
int main()
{
    Insert(first, 0, 3);
    Insert(first, 1, 5);
    Insert(first, 2, 6);
    Insert(first, 3, 7);
    Insert(first, 4, 9);
    Display(first);
    return 0;
}