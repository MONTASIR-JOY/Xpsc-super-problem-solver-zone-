#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n,k;
    cin >> n >> k;
    vector<long long> v(n+2);
    v[0] = 0;
    long long stofmin = 0;
    long long stofpl = 0;
    bool x = true;
    bool y = true;
    long long cnt1 = 0;
    long long cntneg1 = 0;
    for (long long i = 1; i <= n;i++)
    {
        cin >> v[i];
        if(v[i]<0)
        {
            cntneg1++;
        }
        else
        {
            cnt1++;
        }
    }
    long long ans = 0;
    for (long long i = 1; i <= n;i++)
    {
            long long b = i;
            long long cnt = cntneg1;
            long long extra = 0;
            for (long long j = b; j <= n;j+=k)
            {
                if(v[j]==-1)
                {
                    cnt--;
                }
                else{
                    extra++;
                }
            }
            for (long long j = b-k; j >= 1;j-=k)
            {
                if(v[j]==-1)
                {
                    cnt--;
                }
                else{
                    extra++;
                }
            }
            long long a = cnt;
            long long n = cnt1 - extra;

            //cout << i << " -> " << a << " " << n << endl;
            ans = max(ans, abs(a - n));
    }
    for (long long i = 1; i <= n;i++)
    {
            long long b = i;
            long long cnt = cnt1;
            long long extra = 0;
            for (long long j = b; j <= n;j+=k)
            {
                if(v[j]==1)
                {
                    cnt--;
                }
                else{
                    extra++;
                }
            }
            for (long long j = b-k; j >= 1;j-=k)
            {
                if(v[j]==1)
                {
                    cnt--;
                }
                else{
                    extra++;
                }
            }
            long long a = cnt;
            long long n = cntneg1 - extra;

            //cout << i << " -> " << a << " " << n << endl;
            ans = max(ans, abs(a - n));
    }
    cout << ans << endl;
    return 0;
}