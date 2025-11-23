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
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        long long sum = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end());
        vector<long long> pre(n + 1);
        pre[0] = 0;
        pre[1] = v[0];
        for (long long i = 2; i < n+1;i++)
        {
            pre[i] = pre[i - 1] + v[i-1];
        }
        vector<long long> suf(n + 1);
        reverse(v.begin(),v.end());
        suf[0] = 0;
        suf[1] = v[0];
        for (long long i = 2; i < n+1;i++)
        {
            suf[i] = suf[i - 1] + v[i-1];
        }
        long long ans = 0;

        for (long long i = 0; i <= k;i++)
        {
            long long pichontekebaad = i;
            long long samnethekebaad = (k - i) * 2;
            //cout <<i<<" "<< pre[samnethekebaad] << " " << suf[pichontekebaad] << endl;
            ans = max(ans, sum - suf[pichontekebaad] - pre[samnethekebaad]);
        }
        cout << ans << endl;
    }
    return 0;
}