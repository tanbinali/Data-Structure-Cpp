#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int num = a[i];
        int loop = n;

        while (loop--)
        {
            auto it = find(a.begin(),a.end(),a[i]+1);

            if (it != a.end())
            {
                cnt++;
                break;
            }
        }
    }

    cout << cnt << " ";

    return 0;
}