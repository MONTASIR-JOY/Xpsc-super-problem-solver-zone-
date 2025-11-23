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
        vector<long long> v(n + 2);
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
        }
        long long ans = (n * (n + 1) * (n + 2)) / 6;
        for (long long i = 1; i < n;i++)
        {
            if(v[i]<v[i+1])
            {
                ans -= i * (n - i);
            }
        }
        cout << ans << endl;
    }
    return 0;
}