//ki asilo vai eida

#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin>>t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        reverse(v.begin(), v.end());
        long long val = v[0];
        long long cnt = 0;
        int ans = 0;
        while(cnt<n)
        {
            while(cnt<n && v[cnt]==v[0])
            {
                cnt++;
            }
            for (int i = cnt; i < min(n, 2 * cnt);i++)
            {
                if(v[i]!=v[0])
                {
                    ans++;
                    break;
                }
            }
            cnt *= 2;
        }
        cout << ans << endl;
    }
    return 0;
}