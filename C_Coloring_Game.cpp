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
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        
        sort(v.begin(), v.end());
        long long ans = 0;

        for (long long i = 2; i < n;i++)
        {
            long long mx = max(v[i], v[n-1] - v[i]);

            long long l = 0;
            long long r = i - 1;
            while(l<r)
            {
                if(v[l]+v[r]>mx)
                {
                    ans += (r - l);
                    r--;
                }
                else
                {
                    l++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}