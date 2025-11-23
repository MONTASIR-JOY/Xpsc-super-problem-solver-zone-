#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);

        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        long long ans = 0;
        v.erase(unique(v.begin(), v.end()), v.end());
        n = v.size();

        for (long long i = 0; i < n; i++)
        {
            if(i==n-1 || i==0 || v[i]>v[i+1] && v[i]>v[i-1] || v[i]<v[i+1] && v[i]<v[i-1])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
