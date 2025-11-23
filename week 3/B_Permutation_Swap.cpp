#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n+1);
        v[0] = 0;
        int mx = 0;
        set<int> se;
        for (int i = 1; i <= n; i++)
        {
            cin >> v[i];
            se.insert(abs(v[i] - i));
        }
        se.erase(0);
        if(se.empty())
        {
            cout << 1 << endl;
        }
        else
        {
            int gcd = 0;
            for(int i:se)
            {
                gcd = __gcd(gcd, i);
            }
            cout << gcd << endl;
        }
    }
    return 0;
}