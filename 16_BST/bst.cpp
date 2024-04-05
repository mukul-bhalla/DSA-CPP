#include <iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;
void Insert(int key)
{
    struct Node *t = root;
    struct Node *r, *p;
    if (root == NULL)
    {
        p = new Node;
        p->data = key;
        p->lchild = NULL;
        p->rchild = NULL;
        root = p;
        return;
    }
    while (t != NULL)
    {
        r = t;
        if (key < t->data)
        {
            t = t->lchild;
        }
        else if (key > t->data)
        {
            t = t->rchild;
        }
        else
        {
            return;
        }
    }
    p = new Node;
    p->data = key;
    p->lchild = NULL;
    p->rchild = NULL;
    if (key < r->data)
    {
        r->lchild = p;
    }
    else
    {
        r->rchild = p;
    }
}

struct Node *R_Insert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (p->data > key)
    {
        p->lchild = R_Insert(p->lchild, key);
    }
    else
    {
        p->rchild = R_Insert(p->rchild, key);
    }
    return p;
}

int Height(struct Node *p)
{
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}

struct Node *InPre(struct Node *p)
{
    while (p && p->rchild != NULL)
    {
        p = p->rchild;
    }
    return p;
}
struct Node *InSucc(struct Node *p)
{
    while (p && p->lchild != NULL)
    {
        p = p->lchild;
    }
    return p;
}

struct Node *Delete(struct Node *p, int key)
{
    struct Node *q;

    if (p == NULL)
    {
        return NULL;
    }
    if (p->lchild == NULL && p->rchild == NULL)
    {
        if (p == root)
            root = NULL;
        delete p;
        return NULL;
    }

    if (key < p->data)
    {
        p->lchild = Delete(p->lchild, key);
    }
    else if (key > p->data)
    {
        p->rchild = Delete(p->rchild, key);
    }
    else
    {
        if (Height(p->lchild) > Height(p->rchild))
        {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        }
        else
        {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}

void InOrder(struct Node *t)
{
    if (t)
    {
        InOrder(t->lchild);
        cout << t->data << " ";
        InOrder(t->rchild);
    }
}

struct Node *Search(int key)
{
    struct Node *t = root;
    while (t != NULL)
    {
        if (t->data == key)
        {
            return t;
        }
        else if (t->data > key)
        {
            t = t->lchild;
        }
        else
        {
            t = t->rchild;
        }
    }
    return NULL;
}
int main()
{
    root = R_Insert(root, 10);
    R_Insert(root, 25);
    R_Insert(root, 15);
    R_Insert(root, 40);
    R_Insert(root, 35);
    R_Insert(root, 45);
    Delete(root, 10);
    InOrder(root);
    return 0;
}