#include <iostream>
using namespace std;
struct Circular_Queue
{
    int size, front, rear;
    int *A;
};
void Create(struct Circular_Queue *q, int size)
{
    q->size = size;
    q->front = q->rear = 0;
    q->A = new int[q->size];
}
void Enqueue(struct Circular_Queue *q, int x)
{
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue Overflow";
    else
    {
        q->rear = (q->rear + 1) % q->size;
        q->A[q->rear] = x;
    }
}
int Dequeue(struct Circular_Queue *q)
{
    int x = -1;
    if (q->front == q->rear)
        cout << "Queue Underflow !!" << endl;
    else
    {
        q->front = (q->front + 1) % q->size;
        x = q->A[q->front];
    }
    return x;
}
void Display(struct Circular_Queue q)
{
    int i = q.front + 1;
    do
    {
        cout << q.A[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
}
int main()
{
    struct Circular_Queue q;
    Create(&q, 5);
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    // Enqueue(&q, 5);
    Dequeue(&q);
    cout << endl;
    Display(q);
    // Enqueue(&q, 6);
    return 0;
}