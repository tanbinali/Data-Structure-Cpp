#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        string s;
        getline(cin,s);
        stringstream ss(s);
        string word;
        map<string,int> mp;
        string high;
        int cnt = 0;
        while(ss >> word)
        {
            mp[word]++;
            if (mp[word] > cnt)
            {
                high = word;
                cnt = mp[word];
            }
        }
        cout << high << " " << cnt << endl;
    }
    return 0;
}