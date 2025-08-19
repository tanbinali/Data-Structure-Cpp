#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    head = newnode;
    if (tail == NULL)
    {
        tail = newnode;
    }
}

void insert_at_tail(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    if (head == NULL)
    {
        head = newnode;
        tail = newnode;
        return;
    }
    tail->next = newnode;
    tail = newnode;
}

void dlt_at_idx(Node *&head, Node *&tail, int idx)
{
    if (idx == 0)
    {
        Node *dltnode = head;
        head = head->next;
        delete dltnode;
        if (head == NULL)
        {
            tail = NULL;
        }
        return;
    }

    Node *tmp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *deleteNode = tmp->next;
    tmp->next = deleteNode->next;
    if (deleteNode == tail)
    {
        tail = tmp;
    }
    delete deleteNode;
}

void dlt_at_head(Node *&head)
{
    Node *dltnode = head;
    head = head->next;
    delete dltnode;
}

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int q, size = 0;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            insert_at_head(head, tail, v);
            size++;
        }
        if (x == 1)
        {
            insert_at_tail(head, tail, v);
            size++;
        }
        if (x == 2)
        {
            if (v >= 0 && v < size)
            {
                dlt_at_idx(head, tail, v);
                size--;
            }
        }

        print_linked_list(head);
        cout << endl;
    }

    return 0;
}