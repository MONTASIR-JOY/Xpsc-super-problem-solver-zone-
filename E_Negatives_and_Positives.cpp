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
        long long mn = LLONG_MAX;
        long long cnt = 0;
        long long sum = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mn = min(mn, abs(v[i]));
            if(v[i]<0)
            {
                cnt++;
            }
            sum += abs(v[i]);
        }
        if(cnt%2==0)
        {
            cout << sum << endl;
        }
        else
        {
            cout << sum - 2*mn << endl;
        }
    }
    return 0;
}