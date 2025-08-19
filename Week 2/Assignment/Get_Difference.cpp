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

void print_linked_list(Node* head)
{
    Node* tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
    
}

void max_min_diff(Node* head)
{
    int max = INT_MIN;
    int min = INT_MAX;

    Node* tmp = head;
    while (tmp != NULL)
    {
        if (tmp->value > max)
        {
            max = tmp->value;
        }
        if (tmp->value < min)
        {
            min = tmp->value;
        }
        tmp = tmp->next;
    }

    int diff = max - min;

    cout << diff;
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

    max_min_diff(head);

    //print_linked_list(head);

    return 0;
}