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
        vector<long long> v(n+2);
        v[0] = 0;
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
        }
        long long leftsum = 0;
        long long rightsum = 0;
        long long ans = 0;
        long long l = 0;
        long long r = n+1;
        while(l<r)
        {
            if(leftsum<rightsum)
            {
                l++;
                leftsum += v[l];
            }
            else
            {
                r--;
                rightsum += v[r];
            }
            if(leftsum==rightsum && l<r)
            {
                ans = max(ans, n - r + 1 + l);
            }
        }
        cout << ans << endl;
    }
    return 0;
}