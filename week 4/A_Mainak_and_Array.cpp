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
        cin>>n;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        if(n==1)
        {
            cout << 0 << endl;
            continue;
        }
        if(n==2)
        {
            cout << abs(v[0] - v[1]) << endl;
            continue;
        }
        long long mx = LLONG_MIN;
        for (long long i = 0; i < n-1;i++)
        {
            mx = max(mx, v[i] - v[i + 1]);
        }
        for (long long i = 1; i < n;i++)
        {
            mx = max(mx, v[i] - v[0]);
        }
         for (long long i = 0; i < n-1;i++)
        {
            mx = max(mx, v[n-1] - v[i]);
        }
        cout << mx << endl;
    }
    return 0;
}