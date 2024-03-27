#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    Node *rchild;
};

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
        front = rear = -1;
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

class NodeS
{
public:
    Node *data;
    NodeS *next;
};
class Stack
{
private:
    NodeS *top;

public:
    Stack()
    {
        top = NULL;
    }
    void Push(Node *x);
    Node *Pop();
    void Display();
    int isEmpty();
};
int Stack::isEmpty()
{
    if (top == NULL)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
void Stack::Push(Node *x)
{
    NodeS *t = new NodeS;
    if (t == NULL)
        cout << "Stack Overflow !" << endl;
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
Node *Stack ::Pop()
{
    Node *x = NULL;
    if (top != NULL)
    {
        NodeS *t = top;
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
    NodeS *t = top;
    while (t)
    {
        cout << t->data << " ";
        t = t->next;
    }
    cout << endl;
}

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
    int height(Node *p);
    void IPreOrder(Node *p);
    void IPostOrder(Node *p);
    void IInOrder(Node *p);
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
int Tree::height(struct Node *p)
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

void Tree::IPreOrder(struct Node *p)
{
    Stack stk;
    while (p || stk.isEmpty())
    {
        if (p)
        {
            cout << p->data;
            stk.Push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.Pop();
            p = p->rchild;
        }
    }
}
void Tree::IInOrder(struct Node *p)
{
    Stack stk;
    while (p || stk.isEmpty())
    {
        if (p)
        {

            stk.Push(p);
            p = p->lchild;
        }
        else
        {
            p = stk.Pop();
            cout << p->data;
            p = p->rchild;
        }
    }
}

void levelOrder(struct Node *p)
{
    Queue q(15);
    cout << p->data << endl;
    q.enqueue(p);
    while (!q.isEmpty())
    {
        p = q.dequeue();
        if (p->lchild)
        {
            cout << p->lchild->data;
            q.enqueue(p->lchild);
        }
        if (p->rchild)
        {
            cout << p->rchild->data << endl;
            q.enqueue(p->rchild);
        }
    }
}

int count(struct Node *p)
{
    if (p)
    {
        return count(p->lchild) + count(p->rchild) + 1;
    }
    return 0;
}

int height(struct Node *p)
{
    int x = 0, y = 0;
    if (!p)
    {
        return 0;
    }
    x = height(p->lchild);
    y = height(p->rchild);
    if (x > y)
    {
        return x + 1;
    }
    else
    {
        return y + 1;
    }
}

int main()
{
    Tree t;
    t.CreateTree();
    // levelOrder(t.root);
    // t.IInOrder(t.root);
    // t.levelOrder(t.root);
    // cout << t.height(t.root);
    cout << count(t.root) << endl;
    cout << height(t.root);
    return 0;
}