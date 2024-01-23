#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack()
    {
        top = NULL;
    }
    void Push(int x);
    int Pop();
    void Display();
};
void Stack::Push(int x)
{
    Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow !" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int Stack ::Pop()
{
    int x = -1;
    if (top != NULL)
    {
        Node *t = top;
        top = top->next;
        x = t->data;
        delete t;
    }
    else
    {
        cout << "Stack Underflow !";
    }

    return x;
}
void Stack::Display()
{
    Node *t = top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}
int main()
{
    Stack stk;
    stk.Push(1);
    stk.Push(2);
    stk.Push(3);
    stk.Push(4);
    cout << stk.Pop() << endl;
    stk.Display();
    return 0;
}