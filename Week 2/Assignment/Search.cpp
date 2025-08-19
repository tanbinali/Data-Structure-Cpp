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

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

void search_num(Node *head, int val)
{
    Node* tmp = head;
    int idx = 0;
    bool found = false;
    while (tmp != NULL)
    {
        if (tmp->value == val)
        {
            cout << idx << endl;
            found = true;
            break;
        }
        idx++;
        tmp = tmp->next;
    }

    if (found == false)
    {
        cout << "-1" << endl;
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        Node *head = NULL;
        Node *tail = NULL;

        int val, x;

        while (1)
        {
            cin >> val;
            if (val == -1)
            {
                break;
            }
            insert_at_tail(head, tail, val);
        }

        cin >> x;
        search_num(head, x);
    }

    return 0;
}