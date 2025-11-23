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
        long long w, h;
        cin >> w >> h;
        long long k1;
        cin >> k1;
        long long mx = LLONG_MIN;
        vector<long long> v(k1);
        for (long long i = 0; i < k1;i++)
        {
            cin >> v[i];
        }
        mx = max(mx, (v[k1-1] - v[0]) * h);

        long long k2;
        cin >>k2;
        vector<long long> v2(k2);
        for (long long i = 0; i < k2;i++)
        {
            cin >> v2[i];
        }
        mx = max(mx, (v2[k2-1] - v2[0]) * h);
        long long k3;
        cin >> k3;
        vector<long long> v3(k3);
        for (long long i = 0; i < k3;i++)
        {
            cin >> v3[i];
        }
        mx = max(mx, (v3[k3-1] - v3[0]) * w);
        long long k4;
        cin >> k4;
        vector<long long> v4(k4);
        for (long long i = 0; i < k4;i++)
        {
            cin >> v4[i];
        }
        mx = max(mx, (v4[k4-1] - v4[0]) * w);

        cout << mx << endl;
    }
    return 0;
}