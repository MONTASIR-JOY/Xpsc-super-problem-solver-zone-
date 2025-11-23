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
        int n, m;
        cin >> n >> m;
        int a[n][m];
        int mn = INT_MAX;
        int ans = 0;
        int cnt = 0;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < m;j++)
            {
                cin >> a[i][j];
                ans += abs(a[i][j]);
                mn = min(mn, abs(a[i][j]));
                if(a[i][j]<0)
                {
                    cnt++;
                }
            }
        }
        if(cnt%2==1)
        {
            ans -= 2 * (mn);
            cout << ans << endl;
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}