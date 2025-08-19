#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    stack<int> a;
    queue<int> b;

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