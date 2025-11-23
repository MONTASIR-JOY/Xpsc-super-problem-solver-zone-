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
        string s;
        cin >> s;
        set<int> se;
        int n = s.size();
        int k = 0;
        for (int i = 0; i < n;i++)
        {
            if(se.find(s[i])==se.end())
            {
                se.insert(s[i]);
            }
            else{
                k = i;
                break;
            }
        }
        bool ans = true;
        for (int i = k; i < n;i++)
        {
            if(s[i]!=s[i-k])
            {
                ans = false;
            }
        }
        if(ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}