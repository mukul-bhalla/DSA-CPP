#include <iostream>
using namespace std;
class Queue
{
private:
    int size, front, rear;
    int *A;

public:
    Queue(int size)
    {
        this->size = size;
        front = rear = -1;
        A = new int[this->size];
    }
    void Enqueue(int x);
    int Dequeue();
    void Display();
    ~Queue()
    {
        delete[] A;
    }
};
void Queue::Enqueue(int x)
{
    if (rear == size - 1)
    {
        cout << "Queue Overflow" << endl;
    }
    else
    {
        A[++rear] = x;
    }
}
int Queue::Dequeue()
{
    int x = -1;
    if (rear == front)
    {
        cout << "Queue Underflow" << endl;
    }
    else
    {
        x = A[++front];
    }
    return x;
}
void Queue::Display()
{
    int i;
    for (i = front + 1; i <= rear; i++)
    {
        cout << A[i] << " ";
    }
}
int main()
{
    Queue q(5);
    q.Enqueue(1);
    q.Enqueue(2);
    q.Enqueue(3);
    q.Enqueue(4);
    q.Enqueue(5);
    cout << q.Dequeue();
    cout << endl;
    q.Display();
    // q.Enqueue(6);
    return 0;
}