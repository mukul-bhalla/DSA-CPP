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

        if (t->data < key)
        {
            t = t->rchild;
        }
        else if (t->data > key)
        {
            t = t->lchild;
        }
        else
        {
            return;
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
}

void Inorder(struct Node *p)
{
    if (p)
    {
        Inorder(p->lchild);
        cout << p->data << " ";
        Inorder(p->rchild);
    }
}
int main()
{
    Insert(10);
    Insert(5);
    Insert(20);
    Insert(8);
    Insert(30);
    Inorder(root);

    return 0;
}