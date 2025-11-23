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
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        long long l = 0;
        long long r = 1;
        long long mx = 1;
        while(r<n)
        {
            if(v[r]-v[r-1]>k)
            {
                l = r;
                // cout << v[r] << endl;
            }
            else{
                mx = max(mx, r - l + 1);
            }
            r++;
        }
        cout << n-mx << endl;
    }
    return 0;
}