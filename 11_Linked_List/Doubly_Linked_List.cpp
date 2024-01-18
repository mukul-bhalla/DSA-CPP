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
int main()
{
    int A[] = {3, 4, 6, 7, 9};
    create(A, 5);
    Display(first);
    cout << count(first);
    return 0;
}