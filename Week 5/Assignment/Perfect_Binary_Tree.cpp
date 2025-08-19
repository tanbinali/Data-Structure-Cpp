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
    Node *root;
    if (val == -1)
        root = NULL;
    else
        root = new Node(val);
    queue<Node *> q;
    if (root)
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

int max_depth(Node *root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    int l = max_depth(root->left);
    int r = max_depth(root->right);
    return max(l, r) + 1;
}

int tree_size(Node *root)
{
    if (root == NULL)
        return 0;
    int l = tree_size(root->left);
    int r = tree_size(root->right);
    return l + r + 1;
}

int main()
{
    Node *root = tree_input();
    int depth = max_depth(root);
    int lhs = tree_size(root);
    int powdepth = 1, rhs;

    for (int i = 0; i < depth; i++)
    {
        powdepth *= 2;
    }

    rhs = powdepth - 1;

    if (lhs == rhs)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}