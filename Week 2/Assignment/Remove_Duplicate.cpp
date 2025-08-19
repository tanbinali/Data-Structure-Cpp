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

void remove_duplicates(Node *&head, Node *&tail)
{
    Node *i = head;

    while (i != NULL)
    {
        Node *j = i;
        while (j->next != NULL)
        {
            if (j->next->value == i->value)
            {
                Node *duplicateNode = j->next;
                j->next = j->next->next;

                if (duplicateNode == tail)
                {
                    tail = j;
                }

                delete duplicateNode;
            }
            else
            {
                j = j->next;
            }
        }
        i = i->next;
    }
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;

    int val;

    while (1)
    {
        cin >> val;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head, tail, val);
    }

    remove_duplicates(head, tail);

    print_linked_list(head);

    return 0;
}