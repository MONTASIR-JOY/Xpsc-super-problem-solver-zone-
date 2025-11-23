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
        long long ans = LLONG_MIN;
        long long r = 0;
        long long sum = 0;
        while(r<n)
        {
            if(sum<0)
            {
                sum = 0;
            }
            if(r>0)
            {
                if(abs(v[r]%2)!=abs(v[r-1]%2))
                {
                    sum += v[r];
                }
                else
                {
                    sum = v[r];
                }
            }
            else
            {
                sum = v[r];
            }
            ans = max(ans, sum);
            r++;
        }
        cout << ans << endl;
    }
    return 0;
}