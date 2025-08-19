#include <bits/stdc++.h>
using namespace std;

int main()
{
    string S;
    cin >> S;

    vector<int> F(26, 0);
    int length = S.length();

    for (int i = 0; i < length; i++)
    {
        char ch = S[i];
        int value = ch - 'a';
        F[value] += 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (F[i] >= 1)
        {
            cout << char(i + 'a') << " : " << F[i] << endl;
        }
    }

    return 0;
}