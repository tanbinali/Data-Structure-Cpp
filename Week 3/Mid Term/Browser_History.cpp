#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<string> l;
    while (1)
    {
        string val;
        cin >> val;
        if (val == "end")
        {
            break;
        }
        l.push_back(val);
    }

    int q;
    cin >> q;
    auto it = l.begin();

    while (q--)
    {
        string s;
        cin >> s;
        it++;
        auto it2 = it;
        it--;

        if (s == "visit")
        {
            string web;
            cin >> web;

            auto found = find(l.begin(), l.end(), web);
            if (found != l.end())
            {
                it = found;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (s == "next")
        {
            if (it != l.end() && it2 != l.end())
            {
                it++;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
        else if (s == "prev")
        {
            if (it != l.begin())
            {
                it--;
                cout << *it << endl;
            }
            else
            {
                cout << "Not Available" << endl;
            }
        }
    }

    return 0;
}
