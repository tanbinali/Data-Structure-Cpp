#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;

    vector<int> a(n + 1);
    vector<long long int> pre(n + 1);

    for (int i = 1; i < a.size(); i++)
    {
        cin >> a[i];
    }

    pre[1] = a[1];

    for (int i = 2; i < a.size(); i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    while (q--)
    {
        int l, r;
        cin >> l >> r;
        long long int sum;
        if (l == 1)
        {
            sum = pre[r];
        }
        else
        {
            sum = pre[r] - pre[l - 1];
        }
        cout << sum << endl;
    }

    return 0;
}