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

void print_linked_list(Node *head)
{
    Node *tmp = head;
    while (tmp != NULL)
    {
        cout << tmp->value << " ";
        tmp = tmp->next;
    }
}

bool ispalindrome(Node *head, Node *tail)
{
    bool flag = false;
    Node *i, *j;
    for ( i = head, j = tail; i != j; i=i->next,j=j->prev)
    {
        if (i->value != j->value)
        {
            flag = true;
            break;
        }
    }
    if (flag == true)
    {
        return false;
    }
    else
    {
        return true;
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

    bool pal = ispalindrome(head, tail);

    if (pal == true)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }    

    return 0;
}
