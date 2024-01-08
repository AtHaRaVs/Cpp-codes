#include <iostream>
using namespace std;

class Node
{
public:
    Node *lchild;
    int data;
    int height;
    Node *rchild;
};

class AVLtree
{
public:
    Node *root = NULL;
    Node *RinsertAVL(Node *p, int key);
    int NodeHeight(Node *p);
    int BalanceFactor(Node *p);
    Node *LLrotation(Node *p);
    Node *LRrotation(Node *p);
};

int AVLtree::NodeHeight(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl > hr ? hl + 1 : hr + 1;
}

int AVLtree::BalanceFactor(Node *p)
{
    int hl, hr;
    hl = p && p->lchild ? p->lchild->height : 0;
    hr = p && p->rchild ? p->rchild->height : 0;

    return hl - hr;
}

Node *AVLtree ::LLrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = p->rchild;

    pl->rchild = p;
    p->lchild = plr;

    pl->height = NodeHeight(pl);
    p->height = NodeHeight(p);

    if (root == p)
    {
        root = pl;
    }

    return pl;
}

Node *AVLtree ::LRrotation(Node *p)
{
    Node *pl = p->lchild;
    Node *plr = p->rchild;

    pl->rchild = plr->lchild;
    p->lchild = plr->rchild;

    plr->lchild = pl;
    plr->rchild = p;

    pl->height = NodeHeight(pl);
    plr->height = NodeHeight(plr);
    p->height = NodeHeight(p);

    if (root == p)
    {
        root = plr;
    }

    return plr;
}

Node *AVLtree::RinsertAVL(Node *p, int key)
{
    Node *t = NULL;
    if (p == NULL)
    {
        t = new Node;
        t->data = key;
        t->height = 1;
        t->lchild = t->rchild = NULL;
        return t;
    }
    if (key < p->data)
    {
        p->lchild = RinsertAVL(p->lchild, key);
    }
    else
    {
        p->rchild = RinsertAVL(p->rchild, key);
    }
    p->height = NodeHeight(p);

    if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == 1)
    {
        return LLrotation(p);
    }
    else if (BalanceFactor(p) == 2 && BalanceFactor(p->lchild) == -1)
    {
        return LRrotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->rchild) == 1)
    {
        // return RLrotation(p);
    }
    else if (BalanceFactor(p) == -2 && BalanceFactor(p->lchild) == -1)
    {
        // return RRrotation(p);
    }
    return p;
}

int main()
{
    AVLtree a;
    a.root = a.RinsertAVL(a.root, 50);
    a.RinsertAVL(a.root,10);
    a.RinsertAVL(a.root,20);
    cout<<"hello";
    return 0;
}