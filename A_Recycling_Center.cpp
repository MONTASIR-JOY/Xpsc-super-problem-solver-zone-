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
        long long n, c;
        cin >> n >> c;
        vector<long long> v(n);
        vector<long long> a;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]<=c)
            {
                a.push_back(v[i]);
            }
        }
        sort(a.rbegin(), a.rend());
        long long zcoin = 0;
        long long mul = 1;
        long long cnt = 0;
        for (long long i = 0; i < a.size();i++)
        {
            mul = 1 << cnt;
            a[i] = a[i] * mul;
            if(a[i]<=c)
            {
                zcoin++;
                cnt++;
            }
        }
        cout << a.size() - zcoin + (n - a.size()) << endl;
    }
    return 0;
}