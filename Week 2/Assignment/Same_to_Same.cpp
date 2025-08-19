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

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;

    int val,size1=0,size2=0;

    while (1)
    {
        cin >> val;
        size1++;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head1, tail1, val);
    }
    while (1)
    {
        cin >> val;
        size2++;
        if (val == -1)
        {
            break;
        }
        insert_at_tail(head2, tail2, val);
    }

    if(size1 != size2)
    {
        cout << "NO";
        return 0;
    }

    Node* tmp1 = head1;
    Node* tmp2 = head2;
    while(tmp1 != NULL)
    {
        if (tmp1->value != tmp2->value)
        {
            cout << "NO";
            return 0;
        }
        tmp1 = tmp1->next;
        tmp2 = tmp2->next;
    }

    cout << "YES";

    return 0;
}