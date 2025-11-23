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
        vector<int>v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }

        int l = 0;
        int r = 1;
        int ans = 0;
        int sz = 0;
        for (int i = 1; i < n;i++)
        {
            if(v[i]%2==v[i-1]%2)
            {
                sz++;
            }
            else{
                ans += sz;
                sz = 0;
            }
        }
        ans += sz;
        cout << ans << endl;
    }
    return 0;
}