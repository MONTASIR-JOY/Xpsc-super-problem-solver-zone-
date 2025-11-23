#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        set<char> se;
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            se.insert(s[i]);
            ans += se.size();
        }
        cout << ans << endl;
    }
    return 0;
}