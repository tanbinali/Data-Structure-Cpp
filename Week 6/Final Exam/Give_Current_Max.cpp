#include <bits/stdc++.h>
using namespace std;

class student
{
public:
    string name;
    int roll;
    int marks;
    student(string name, int roll, int marks)
    {
        this->name = name;
        this->roll = roll;
        this->marks = marks;
    }
};

class cmp
{
public:
    bool operator()(student l, student r)
    {
        if (l.marks != r.marks)
            return l.marks < r.marks;
        return l.roll > r.roll;
    }
};

int main()
{
    int n;
    cin >> n;
    priority_queue<student, vector<student>, cmp> pq;
    while (n--)
    {
        string name;
        int roll, marks;
        cin >> name >> roll >> marks;
        student s(name, roll, marks);
        pq.push(s);
    }
    int q;
    cin >> q;
    while (q--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 0)
        {
            string name;
            int roll, marks;
            cin >> name >> roll >> marks;
            student s(name, roll, marks);
            pq.push(s);
            if (!pq.empty())
            {
                student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            }
        }
        else if (cmd == 1)
        {
            if (!pq.empty())
            {
                student top = pq.top();
                cout << top.name << " " << top.roll << " " << top.marks << endl;
            }
            else
                cout << "Empty" << endl;
        }
        else
        {
            if (!pq.empty())
            {
                pq.pop();
                if (!pq.empty())
                {
                    student top = pq.top();
                    cout << top.name << " " << top.roll << " " << top.marks << endl;
                }
                else
                    cout << "Empty" << endl;
            }
            else
                cout << "Empty" << endl;
        }
    }
    return 0;
}