#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    string s;
    cin >> s;
    string cmp = s;
    sort(cmp.begin(), cmp.end());
    if(cmp==s)
    {
        cout << "NO" << endl;
        return 0;
    }
    map<int, int> mp;
    for (int i = 0; i < n;i++)
    {
        mp[s[i]] = i+1;
    }

    for (int i = 0; i < n;i++)
    {
        if(s[i]!=cmp[i])
        {
            cout << "YES" << endl;
            cout << i + 1 << " " << mp[cmp[i]] << endl;
            return 0;
        }
    }
        return 0;
}