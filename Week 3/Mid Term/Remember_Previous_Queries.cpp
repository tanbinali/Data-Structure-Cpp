#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> l;
    int q, size = 0;
    cin >> q;

    while (q--)
    {
        int x, v;
        cin >> x >> v;

        if (x == 0)
        {
            l.push_front(v);
            size++;
        }
        else if (x == 1)
        {
            l.push_back(v);
            size++;
        }
        else if (x == 2)
        {
            if (v >= 0 && v < size)
            {
                l.erase(next(l.begin(),v));
                size--;
            }
        }

        cout << "L -> ";
        for (auto val : l)
        {
            cout << val << " ";
        }
        cout << endl;

        l.reverse();
        cout << "R -> ";
        for (auto val : l)
        {
            cout << val << " ";
        }
        cout << endl;
        l.reverse();
    }

    return 0;
}
