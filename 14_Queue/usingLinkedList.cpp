#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
void Enqueue(int x)
{
    struct Node *t = new Node;
    if (t == NULL)
        cout << "Queue Full !" << endl;
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
        {
            front = rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int Dequeue()
{
    int x = -1;
    struct Node *p;
    if (front == NULL)
        cout << "Empty Queue" << endl;
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        delete p;
    }
    return x;
}
void Display()
{
    struct Node *p = front;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
}
int main()
{
    Enqueue(1);
    Enqueue(2);
    Enqueue(3);
    Enqueue(4);
    Enqueue(5);
    cout << Dequeue() << endl;

    Display();

    return 0;
}