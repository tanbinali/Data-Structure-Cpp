#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<int> a(n);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        vector<int> sorted(a);
        sort(sorted.begin(), sorted.end());

        int found = 1;

        for (int i = 0; i < n; i++)
        {
            if (a[i] != sorted[i])
            {
                found = 0;
                break;
            }
        }
        if (found == 0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}