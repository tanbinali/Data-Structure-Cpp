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
    if (val == -1) root = NULL;
    else root = new Node(val);
    queue<Node *> q;
    if (root) q.push(root);
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

void reverse_leafs(Node *root)
{
    queue<Node *> q;
    vector<int> v;
    if (root == NULL)
    {
        return;
    }
    q.push(root);
    while (!q.empty())
    {
        Node *p = q.front();
        q.pop();

        if (p->left == NULL && p->right == NULL)
        {
            v.push_back(p->value);
        }

        if (p->left)
            q.push(p->left);
        if (p->right)
            q.push(p->right);
    }
    sort(v.begin(),v.end());
    reverse(v.begin(),v.end());
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    
}

int main()
{
    Node *root = tree_input();
    reverse_leafs(root);

    return 0;
}