#include <iostream>
using namespace std;
struct Node
{
    int val;
    struct Node *next;
} *Top = NULL;
void Push(int x)
{
    struct Node *t = new Node;
    if (t == NULL)
        cout << "Stack Overflow !";
    else
    {
        t->val = x;
        t->next = Top;
        Top = t;
    }
}
int Pop()
{
    struct Node *t;
    int x = -1;
    if (Top == NULL)
    {
        return x;
    }
    t = Top;
    Top = Top->next;
    x = t->val;
    delete t;
    return x;
}
int isOperand(char x)
{
    if (x == '+' || x == '-' || x == '*' || x == '/')
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int Evaluate(string postfix)
{
    int i, x1, x2, r;
    for (i = 0; postfix[i] != '\0'; i++)
    {
        if (isOperand(postfix[i]))
        {
            Push(postfix[i] - '0');
        }
        else
        {
            x2 = Pop();
            x1 = Pop();

            switch (postfix[i])
            {
            case '+':
                r = x1 + x2;
                break;
            case '-':
                r = x1 - x2;
                break;
            case '*':
                r = x1 * x2;
                break;
            case '/':
                r = x1 / x2;
                break;
            default:
                break;
            }
            Push(r);
        }
    }
    return Pop();
}
void Display()
{
    while (Top != NULL)
    {
        cout << Top->val << " ";
        Top = Top->next;
    }
}
int main()
{
    string infix = "35*62/+4-";
    cout << Evaluate(infix);
    return 0;
}