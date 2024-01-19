#include <iostream>
using namespace std;
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *head = NULL;
void Create(int A[], int n)
{
    struct Node *last = NULL, *t = NULL;
    int i;
    head = new Node;
    head->prev = head;
    head->data = A[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->prev = last;
        t->next = head;
        last->next = t;
        head->prev = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != head);
}
int count(struct Node *p)
{
    int x = 0;
    do
    {
        x++;
        p = p->next;
    } while (p != head);
    return x;
}
void Insert(struct Node *p, int pos, int x)
{
    struct Node *t;
    int i;
    if (pos < 0 || pos > count(head))
    {
        cout << "Cannot Insert !";
        return;
    }
    if (pos == 0)
    {

        t = new Node;
        t->data = x;
        t->next = head;
        t->prev = head->prev;
        head->prev->next = t;
        head->prev = t;
    }
    else
    {
        for (i = 0; i < pos - 1; i++)
        {
            p = p->next;
        }
        t = new Node;
        t->data = x;
        t->prev = p;
        t->next = p->next;
        p->next->prev = t;
        p->next = t;
    }
}
int main()
{
    int A[] = {};
    // Create(A, 0);
    Insert(head, 0, 5);
    // cout << head->prev->d;
    Display(head);
    return 0;
}