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
int isEmpty()
{
    return front == NULL;
}

void BFS(int G[][7], int start, int n)
{
    int u;

    int i = start;
    int visited[n + 1]{};
    cout << i << " ";
    visited[i] = 1;
    Enqueue(i);
    while (!isEmpty())
    {
        i = Dequeue();
        int j;
        for (j = 1; j < n; j++)
        {
            if (G[i][j] == 1 && visited[j] == 0)
            {
                cout << j << " ";
                visited[j] = 1;
                Enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    int j;
    static int visited[7] = {0};
    if (visited[start] == 0)
    {
        cout << start << " ";
        visited[start] = 1;
        for (j = 1; j < n; j++)
        {
            if (G[start][j] == 1 && visited[j] == 0)
            {
                // cout << j << " ";
                DFS(G, j, n);
            }
        }
    }
}
int main()
{
    int G[7][7] = {
        {0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 1, 0, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0},
    };
    DFS(G, 1, 7);

    return 0;
}