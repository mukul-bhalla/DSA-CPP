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
void SortedInsert(struct Node **H, int x)
{
    struct Node *t, *q = NULL, *p = *H;
    t = new Node;
    t->data = x;
    t->next = NULL;

    if (*H == NULL)
        *H = t;
    else
    {
        while (p && p->data < x)
        {
            q = p;
            p = p->next;
        }
        if (p == *H)
        {
            t->next = *H;
            *H = t;
        }
        else
        {
            t->next = q->next;
            q->next = t;
        }
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

int hashfn(int key)
{
    return key % 10;
}

void Insert(struct Node *H[], int key)
{
    int index = hashfn(key);
    SortedInsert(&H[index], key);
}

struct Node *Search(struct Node *t, int key)
{
    while (t != NULL)

    {
        // cout << t->data << endl;
        if (t->data == key)
        {
            // cout << "Inside if";
            return t;
        }
        t = t->next;
    }
    return NULL;
}
int main()
{
    struct Node *HT[10];
    struct Node *temp;
    int i;
    for (i = 0; i < 10; i++)
    {
        HT[i] = NULL;
    }
    Insert(HT, 22);
    Insert(HT, 42);
    Insert(HT, 12);

    // Display(HT[2]);
    temp = Search(HT[hashfn(42)], 42);
    cout << temp->data;
    return 0;
}