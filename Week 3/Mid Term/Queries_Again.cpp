#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int value;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->value = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insert_at_head(Node *&head, Node *&tail, int val)
{
    Node *newnode = new Node(val);
    newnode->next = head;
    if (head != NULL)
    {
        head->prev = newnode;
    }
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
    newnode->prev = tail;
    tail = newnode;
}

void insert_at_any_pos(Node *head, int idx, int val)
{
    Node *tmp = head;
    for (int i = 0; i < idx - 1; i++)
    {
        tmp = tmp->next;
    }

    Node *newNode = new Node(val);
    newNode->next = tmp->next;
    tmp->next->prev = newNode;
    tmp->next = newNode;
    newNode->prev = tmp;
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

void reverse_linked_list(Node *tail)
{
    Node *tmp = tail;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->prev;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    int size = 0;

    int q;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x < 0 || x > size)
        {
            cout << "Invalid" << endl;
            continue;
        }
        if (x == 0)
        {
            insert_at_head(head, tail, v);
            size++;
        }
        else if (x == size)
        {
            insert_at_tail(head, tail, v);
            size++;
        }
        else
        {
            insert_at_any_pos(head, x, v);
            size++;
        }

        cout << "L -> ";
        print_linked_list(head);
        cout << endl;

        cout << "R -> ";
        reverse_linked_list(tail);
        cout << endl;
    }

    return 0;
}
