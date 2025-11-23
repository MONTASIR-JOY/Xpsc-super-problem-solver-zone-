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
        long long n, q;
        cin >> n >> q;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<long long> pre(n + 1);
        pre[0] = 0;
        for (long long i = 1; i < n;i++)
        {
            pre[i] = pre[i - 1] + v[i-1];
            //cout << pre[i] << " ";
        }
        pre[n] = pre[n - 1] + v[n - 1];
        //cout << pre[n] << " ";
        while (q--)
        {
            long long l, r, k; 
            cin >> l >> r >> k;
            //cout << pre[l - 1] << " " << (r - l + 1) * k << " " << pre[n] -pre[r] << endl;
            long long s = pre[l - 1] + (r - l + 1) * k + pre[n] - pre[r];
            if(s%2==1)
            {
                cout << "YES" << endl;
            }
            else{
                cout << "NO" << endl;
            }
        }
    }
    return 0;
}