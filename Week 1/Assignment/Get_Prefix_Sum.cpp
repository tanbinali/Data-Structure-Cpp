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

    for (int i = 0, j = n - 1; i < j; i++, j--)
    {
        long long int temp = pre[i];
        pre[i] = pre[j];
        pre[j] = temp;
    }

    for (int i = 0; i < n; i++)
    {
        cout << pre[i] << " ";
    }

    return 0;
}