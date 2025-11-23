#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        string s;
        cin >> s;

        set<char> suf, pre;
        map<char, int> mp;
        for (long long i = 0; i < n; i++)
        {
            suf.insert(s[i]);
            mp[s[i]]++;
        }
        long long ans = suf.size();

        for (long long i = 0; i < n; i++)
        {
            mp[s[i]]--;
            if(mp[s[i]]==0)
            {
                suf.erase(s[i]);
            }
            pre.insert(s[i]);
            ans = max(ans, (long long)(suf.size() + pre.size()));
        }
        cout << ans << endl;
    }
    return 0;
}