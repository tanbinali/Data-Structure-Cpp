#include <bits/stdc++.h>
using namespace std;
int main()
{
    int q;
    cin >> q;
    queue<string> cnt;
    while (q--)
    {
        int cmd;
        cin >> cmd;
        if (cmd == 0)
        {
            string s;
            cin >> s;
            cnt.push(s);
        }
        else if (cmd == 1)
        {
            if (!cnt.empty())
            {
                cout << cnt.front() << endl;
                cnt.pop();
            }
            else
            {
                cout << "Invalid"
                     << endl;
            }
        }
    }
    return 0;
}