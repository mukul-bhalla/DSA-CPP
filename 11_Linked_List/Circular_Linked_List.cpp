#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *head = NULL;
void create(int A[], int n)
{
    int i;
    struct Node *last, *t;
    head = new Node;
    head->data = A[0];
    head->next = head;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void Display(struct Node *p)
{
    do
    {
        cout << p->data << "  ";
        p = p->next;
    } while (p != head);
}

void RDisplay(struct Node *p)
{
    static int flag = 0;
    if (p != head || flag == 0)
    {
        cout << p->data << " ";
        flag = 1;
        RDisplay(p->next);
    }
    flag = 0;
}
int count(struct Node *p)
{
    int c = 0;
    do
    {
        c++;
        p = p->next;
    } while (p != head);
    return c;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (index < 0 || index > count(head))
    {
        cout << "Index out of range !";
    }
    if (index == 0)
    {
        t = new Node;
        t->data = x;
        if (head == NULL)
        {
            head = t;
            head->next = head;
        }
        else
        {
            while (p->next != head)
                p = p->next;
            p->next = t;
            t->next = head;
            head = t;
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t = new Node;
        t->data = x;
        t->next = p->next;
        p->next = t;
    }
}
int Delete(struct Node *p, int pos)
{
    struct Node *q = NULL, *t = NULL;
    int i, x;
    if (pos < 0 || pos > count(head) || p == NULL)
    {
        cout << "Not Possible";
        return -1;
    }
    if (pos == 1)
    {
        // t = head;
        while (p->next != head)
        {
            p = p->next;
        }
        x = head->data;
        if (head == p)
        {
            delete head;
            head = NULL;
        }
        else
        {
            p->next = head->next;
            q = head;
            head = q->next;
            delete q;
        }
    }
    else
    {
        for (i = 0; i < pos - 2; i++)
        {
            p = p->next;
        }
        q = p->next;
        p->next = q->next;
        x = q->data;
        delete q;
    }
    return x;
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    // RDisplay(head);
    // Insert(head, 0, 5);
    cout << Delete(head, 2) << endl;
    Display(head);
    return 0;
}