#include <iostream>
using namespace std;
struct Node
{
    struct Node *lchild;
    int data;
    int height;
    struct Node *rchild;
} *root = NULL;

int NodeHeight(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;
    if (hl > hr)
    {
        return hl + 1;
    }
    return hr + 1;
}

int balanceFactor(struct Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

struct Node *LLRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = p;
    p->lchild = plr;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);

    if (p == root)
    {
        root = pl;
    }
    return pl;
}

struct Node *LRRotation(struct Node *p)
{
    struct Node *pl = p->lchild;
    struct Node *plr = pl->rchild;
    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;
    plr->lchild = pl;
    plr->rchild = p;

    p->height = NodeHeight(p);
    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);

    if (p == root)
    {
        root = plr;
    }
    return plr;
}

struct Node *R_Insert(struct Node *p, int key)
{
    struct Node *t;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1;
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
    p->height = NodeHeight(p);

    if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == 1)
        return LLRotation(p);
    else if (balanceFactor(p) == 2 && balanceFactor(p->lchild) == -1)
        return LRRotation(p);
    // else if (balanceFactor(p) == -2 && balanceFactor(p->lchild) == -1)
    //     return RRRotation(p);
    // else if (balanceFactor(p) == -2 && balanceFactor(p->lchild) == 1)
    //     return RLRotation(p);

    return p;
}

void InOrder(struct Node *p)
{
    InOrder(p->lchild);
    cout << p->data;
    InOrder(p->rchild);
}

int main()
{
    root = R_Insert(root, 50);
    R_Insert(root, 10);
    R_Insert(root, 20);

    cout << root->data;

    return 0;
}