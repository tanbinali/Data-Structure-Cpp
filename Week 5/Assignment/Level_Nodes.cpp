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

void level_print(Node *root, int lvl)
{
    queue<pair<Node *, int>> q;
    if (root)
        q.push({root, 0});

    bool found = false;
    while (!q.empty())
    {
        pair<Node *, int> parent = q.front();
        q.pop();

        Node *node = parent.first;
        int level = parent.second;

        if (level == lvl)
        {
            cout << node->value << " ";
            found = true;
        }
        if (node->left)
            q.push({node->left, level + 1});
        if (node->right)
            q.push({node->right, level + 1});
    }

    if (!found)
        cout << "Invalid";
}

int main()
{
    Node *root = tree_input();
    int lvl;
    cin >> lvl;
    level_print(root,lvl);
    return 0;
}