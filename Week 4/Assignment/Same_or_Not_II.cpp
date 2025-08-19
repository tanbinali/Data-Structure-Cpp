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

class myStack
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
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
    void pop()
    {
        sz--;
        Node *delnode = tail;
        tail = tail->prev;
        delete delnode;
        if (tail == NULL)
        {
            head = NULL;
            return;
        }
        tail->next = NULL;
    }
    int top ()
    {
        return tail->value;
    }
    int size ()
    {
        return sz;
    }
    bool empty()
    {
        return head == NULL;
    }
};

class myQueue
{
public:
    Node *head = NULL;
    Node *tail = NULL;
    int sz = 0;

    void push(int val)
    {
        sz++;
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
    void pop()
    {
        sz--;
        Node *delnode = head;
        head = head->next;
        delete delnode;
        if (head == NULL)
        {
            tail = NULL;
            return;
        }
        head->prev = NULL;
    }
    int front ()
    {
        return head->value;
    }
    int size ()
    {
        return sz;
    }
    bool empty()
    {
        return head == NULL;
    }
};

int main()
{
    int n, m;
    cin >> n >> m;
    myStack a;
    myQueue b;

    while (n--)
    {
        int val;
        cin >> val;
        a.push(val);
    }
    while (m--)
    {
        int val;
        cin >> val;
        b.push(val);
    }

    int sval, qval;
    bool isSame = true;

    if (a.size() != b.size())
    {
        cout << "NO";
        return 0;
    }

    while (!a.empty() && !b.empty())
    {
        sval = a.top();
        a.pop();
        qval = b.front();
        b.pop();

        if (sval != qval)
        {
            isSame = false;
            break;
        }
    }

    if (isSame)
        cout << "YES";
    else
        cout << "NO";

    return 0;
}