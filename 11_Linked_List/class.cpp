#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class LinkedList
{
private:
    Node *first;

public:
    LinkedList()
    {
        first = NULL;
    }
    LinkedList(int A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, int x);
    int Length();
};
LinkedList::LinkedList(int A[], int n)
{
    Node *last, *t;
    int i = 0;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    for (int i = 1; i < n; i++)
    {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
LinkedList::~LinkedList()
{
    Node *p = first;
    while (first)
    {
        first = first->next;
        delete p;
        p = first;
    }
}
void LinkedList::Display()
{
    Node *t = first;
    while (t != NULL)
    {
        cout << t->data << " ";
        t = t->next;
    }
}
int LinkedList::Length()
{
    int count = 0;
    Node *t = first;
    while (t != NULL)
    {
        count++;
        t = t->next;
    }
    return count;
}
void LinkedList::Insert(int index, int x)
{
    Node *t = new Node;
    int i;
    t->data = x;
    if (index < 0 || index > Length())
    {
        cout << "Insertion Not Possible!";
    }
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        Node *x = first;
        for (i = 1; i < index; i++)
        {
            x = x->next;
        }
        t->next = x->next;
        x->next = t;
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    LinkedList obj(A, 5);
    obj.Insert(6, 5);
    obj.Display();
    // cout << obj.Length();
    return 0;
}