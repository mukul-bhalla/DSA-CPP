#include <iostream>
using namespace std;
struct Node
{
    char data;
    struct Node *next;
} *Top = NULL;
void Push(char x)
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
int isBalanced(string str)
{
    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
        if (str[i] == '(')
            Push(str[i]);
        else if (str[i] == ')')
        {
            if (!Top)
            {
                return 0;
            }
            Pop();
        }
    }
    if (Top == NULL)
        return 1;
    return 0;
}
int main()
{
    string exp = "((A+B)*(C-D)))";
    cout << isBalanced(exp);
    return 0;
}