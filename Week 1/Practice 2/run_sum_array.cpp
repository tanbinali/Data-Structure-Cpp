#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<long long int> pre(n);

    for (int i = 0; i < a.size(); i++)
    {
        cin >> a[i];
    }

    pre[0] = a[0];

    for (int i = 1; i < a.size(); i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }

    for (int i = 0; i < pre.size(); i++)
    {
        cout << pre[i] << " ";
    }

    return 0;
}