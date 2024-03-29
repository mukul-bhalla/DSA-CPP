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
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    InOrder(root);
    // cout << endl;
    // cout << root->lchild->data;
    // cout << Search(3)->data;
    struct Node *s = Search(200);
    if (s)
    {
        cout << s->data;
    }
    else
    {
        cout << "Not found";
    }
    return 0;
}