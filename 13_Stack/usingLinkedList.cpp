#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *Top = NULL;
void Push(int x)
{
    struct Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow" << endl;
    else
    {
        t->data = x;
        t->next = Top;
        Top = t;
    }
}
int Pop()
{
    int x = -1;
    if (Top == NULL)
    {
        cout << "Stack Underflow !";
    }
    else
    {
        struct Node *p = Top;
        Top = Top->next;
        x = p->data;
        delete p;
    }
    return x;
}
int Peek(int pos)
{
    struct Node *p = Top;
    int i;

    for (i = 0; p != NULL && i < pos - 1; i++)
        p = p->next;
    return p->data;
    if (p)
        return p->data;
    return -1;
}
void Display()
{
    struct Node *t = Top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
}
int main()
{
    Push(1);
    Push(2);
    Push(3);
    Push(4);
    cout << Peek(3);
    // Display();
    // cout << Pop();
    // cout << endl;
    // Display();
    return 0;
}