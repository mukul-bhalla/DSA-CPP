#include <iostrteam>
using namespace std;
class Queue
{
private:
    int front;
    int rear;
    int size;
    Node **Q;

public:
    Queue()
    {
        front = rear = 11;
        size = 10;
        Q = new Node *[size];
    }
    Queue(int n)
    {
        front = rear = -1;
        size = n;
        Q = new Node *[size];
    }
    void enqueue(Node *x)
    {
        if (rear == size - 1)
        {
            cout << "Queue is Full !";
        }
        else
        {
            rear = rear + 1;
            Q[rear] = x;
        }
    }
    Node *dequeue()
    {
        Node *x = NULL;
        if (front == rear)
            cout << "Queue is Empty";
        else
        {
            x = Q[front + 1];
            front++;
        }
        return x;
    }
    int isEmpty()
    {
        if (rear == front)
        {
            return 1;
        }
        return 0;
    }
};

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};
class Tree
{
public:
    Node *root;
    Tree()
    {
        root = NULL;
    }
    void CreateTree();
    void preOrder(Node *p);
    void inOrder(Node *p);
    void postOrder(Node *p);
    void levelOrder(Node *p);
    void height(Node *p);
};
void Tree ::CreateTree()
{
    Node *p, *t;
    int x;
    Queue q(100);
    cout << "Enter root value:";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}
void Tree::preOrder(struct Node *p)
{
    if (p)
    {
        cout << p->data << " ";
        preOrder(p->lchild);
        preOrder(p->rchild);
    }
}
void Tree::inOrder(struct Node *p)
{
    if (p)
    {
        inOrder(p->lchild);
        cout << p->data << " ";
        inOrder(p->rchild);
    }
}
void Tree::postOrder(struct Node *p)
{
    if (p)
    {
        postOrder(p->lchild);
        postOrder(p->rchild);
        cout << p->data << " ";
    }
}
void Tree::levelOrder(struct Node *p)
{
    Queue q(100);
    cout << root->data;
    q.enqueue(root);
    while (!q.isEmpty())
    {
        root = q.dequeue();
        if (root->lchild)
        {
            cout << root->lchild->data;
            q.enqueue(root->lchild);
        }
        if (root->rchild)
        {
            cout << root->rchild->data;
            q.enqueue(root->rchild);
        }
    }
}
void Tree::height(struct Node *p)
{
    int x = 0, y = 0;
    if (root == 0)
        return 0;
    x = height(root->lchild);
    y = height(root->rchild);
    if (x > y)
        return x + 1;
    else
        return y + 1;
}
int main()
{

    return 0;
}