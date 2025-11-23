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
        long long n, k;
        cin >> n >> k;
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

        long long ans = LLONG_MIN;
        long long mxb = LLONG_MIN;
        vector<long long> pre(n);
        pre[0] = a[0];
        for (long long i = 1; i < n;i++)
        {
            pre[i] = pre[i - 1] + a[i];
        }

        for (long long i = 0; i < n;i++)
        {
            if(i>=k)
            {
                break;
            }
            mxb = max(b[i], mxb);
            long long sum = pre[i] + (k - i-1) * mxb;
            ans = max(ans, sum);
        }
        cout << ans << endl;
    }
    return 0;
}