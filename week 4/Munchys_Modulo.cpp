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
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }

        sort(v.rbegin(), v.rend());
        long long a = v[0];
        long long b = v[1];
        long long c = v[2];
        long long mx = LLONG_MIN;
        for (int i = 1; i < n;i++)
        {
            for (int j = i + 1;j<n;j++)
            {
                if(i!=j)
                {
                    mx = max(mx, a % (v[i] + v[j]));
                }
            }
        }
        cout << max(mx, b) << endl;
    }
    return 0;
}