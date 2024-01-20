#include <iostream>
#include <stack>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL;
void Create(int A[], int n)
{
    int i;
    struct Node *last = NULL, *t = NULL;
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
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int Count(struct Node *p)
{
    int c = 0;
    while (p)
    {
        c++;
        p = p->next;
    }
    return c;
}
int Middle(struct Node *p)
{
    int idx, i, val;
    if (Count(p) % 2 != 0)
    {
        idx = (Count(p) + 1) / 2;
    }
    else
    {
        idx = (Count(p) / 2);
    }
    for (i = 0; i < idx - 1; i++)
    {
        p = p->next;
    }
    val = p->data;
    return val;
}
int BetterMiddle(struct Node *p)
{
    struct Node *q = p;
    while (p)
    {
        p = p->next;
        if (p)
            p = p->next;
        if (p)
            q = q->next;
    }
    return q->data;
}
int Intersection(struct Node *p, struct Node *q)
{
    stack<Node *> s1, s2;
    while (p)
    {
        s1.push(p);
        p = p->next;
    }
    // cout << s1.top()->data << endl;
    while (q)
    {
        s2.push(q);
        q = q->next;
    }

    while (s1.top() == s2.top())
    {
        // cout << s1.top()->data << " " << s2.top()->data << endl;

        p = s1.top();
        s1.pop();
        s2.pop();
    }
    return p->data;
}
int main()
{
    int A[] = {8, 6, 3, 9, 10, 4};
    int B[] = {2, 3, 0};
    Create(A, 6);
    // Display(first);
    // cout << endl;
    // cout << Count(first);
    // cout << endl;
    // cout << Middle(first);
    // cout << endl;
    // cout << BetterMiddle(first);
    struct Node *second = new Node, *t = NULL, *last = NULL;
    int i;
    second->data = 1;
    second->next = NULL;
    last = second;
    for (i = 0; i < 3; i++)
    {
        t = new Node;
        t->data = B[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    t->next = first->next->next;
    // Display(second);
    cout << Intersection(first, second);

    return 0;
}