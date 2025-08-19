#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<long long int> pre(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    pre[0] = a[0];

    for (int i = 1; i < n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 1; i < n - 1; i++)
    {
        long long int l = pre[i - 1];
        long long r = pre[n - 1] - pre[i];

        if (l == r)
        {
            cout << i;
            break;
        }
    }

    return 0;
}