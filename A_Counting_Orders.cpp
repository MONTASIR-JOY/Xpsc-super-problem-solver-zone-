#include<bits/stdc++.h>
using namespace std;
const long long mod = 109 + 7;
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
        vector<long long>a(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        vector<long long> b(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        long long ans = 1;
        for (long long i = 0; i < n;i++)
        {
            long long it=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            long long cnt = it - i;
            if(it<=i)
            {
                ans = 0;
                break;
            }
            else
            {
                ans = ans * cnt % 1000000007;
            }
        }
        cout << ans << endl;
    }
    return 0;
}