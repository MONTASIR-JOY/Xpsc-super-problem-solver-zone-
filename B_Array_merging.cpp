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

        vector<long long> a(n);
        vector<long long> b(n);
    
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }

        map<long long, long long> mpa;
        map<long long, long long> mpb;
        long long cnt1 = 1;
        for (long long i = 1; i < n;i++)
        {
            if(a[i]==a[i-1])
            {
                cnt1++;
            }
            else{
                mpa[a[i-1]] = max(mpa[a[i-1]], cnt1);
                cnt1 = 1;
            }
        }
        mpa[a[n - 1]] = max(mpa[a[n - 1]], cnt1);
        long long cnt2 = 1;
        for (long long i = 1; i < n;i++)
        {
            if(b[i]==b[i-1])
            {
                cnt2++;
            }
            else{
                mpb[b[i-1]] = max(mpb[b[i-1]], cnt2);
                cnt2 = 1;
            }
        }
        mpb[b[n - 1]] = max(mpb[b[n - 1]], cnt2);
        long long ans = LLONG_MIN;
        for (long long i = 0; i <= 2 * n;i++)
        {
            ans = max(ans, mpa[i] + mpb[i]);
        }
        cout << ans << endl;
    }
    return 0;
}