#include <iostream>
using namespace std;
struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q, int size)
{
    q->size = size;
    q->Q = new int[q->size];
    q->front = q->rear = -1;
}
void Enqueue(struct Queue *q, int x)
{
    if (q->rear == q->size - 1)
    {
        cout << "Queue Overflow";
    }
    else
    {
        q->Q[++q->rear] = x;
    }
}
int Dequeue(struct Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
    {
        cout << "Queue Underflow";
        return x;
    }
    x = q->Q[++q->front];
    return x;
}
void Display(struct Queue q)
{
    while (q.front != q.rear)
    {
        cout << q.Q[++q.front] << " ";
    }
}
int main()
{
    struct Queue q;
    Create(&q, 5);
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    // Enqueue(&q, 6);
    cout << Dequeue(&q) << endl;
    Display(q);

    return 0;
}