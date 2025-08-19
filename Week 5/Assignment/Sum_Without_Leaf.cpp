#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *left;
    Node *right;
    Node(int val)
    {
        this->value = val;
        this->left = NULL;
        this->right = NULL;
    }
};

Node *tree_input()
{
    int val;
    cin >> val;
    Node *root = new Node(val);
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        int l, r;
        cin >> l >> r;
        Node *tl, *tr;
        if (l == -1)
            tl = NULL;
        else
            tl = new Node(l);
        if (r == -1)
            tr = NULL;
        else
            tr = new Node(r);

        p->left = tl;
        p->right = tr;

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return root;
}

int sum_wo_leaf(Node *root)
{
    int sum = 0;
    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        if (!(p->left == NULL && p->right == NULL))
        {
            sum = sum + p->value;
        }

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    return sum;
}

int main()
{
    Node *root = tree_input();
    int sum = sum_wo_leaf(root);
    cout << sum;

    return 0;
}