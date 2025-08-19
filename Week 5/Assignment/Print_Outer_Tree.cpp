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

void print_outer_left(Node *root)
{
    if (root == NULL)
        return;
    if (root->left == NULL)
        print_outer_left(root->right);
    print_outer_left(root->left);
    cout << root->value << " ";
}

void print_outer_right(Node *root)
{
    if (root == NULL)
        return;
    cout << root->value << " ";
    if (root->right == NULL)
        print_outer_right(root->left);
    print_outer_right(root->right);
}

int main()
{
    Node *root = tree_input();
    if (root->left != NULL)
        print_outer_left(root);
    else cout << root->value << " ";
    if (root->right != NULL)
        print_outer_right(root->right);
    return 0;
}