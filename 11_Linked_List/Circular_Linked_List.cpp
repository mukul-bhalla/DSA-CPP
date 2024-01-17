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

int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    RDisplay(head);
    RDisplay(head);
    return 0;
}