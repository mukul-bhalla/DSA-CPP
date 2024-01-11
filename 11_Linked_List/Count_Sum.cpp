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
int Rcount(struct Node *p)
{
    if (p == NULL)
        return 0;
    return Rcount(p->next) + 1;
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

int Rsum(struct Node *p)
{
    if (p == NULL)
        return 0;
    return Rsum(p->next) + p->data;
}

int sum(struct Node *p)
{
    int count = 0;
    while (p != NULL)
    {
        count += p->data;
        p = p->next;
    }
    return count;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50, 60, 70};
    create(A, 7);
    // Display(first);
    // cout << Rcount(first);
    // cout << count(first);
    // cout << Rsum(first);
    cout << sum(first);
    return 0;
}