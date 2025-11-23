#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n, q;
        cin >> n >> q;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<long long> x(q);
        for (long long i = 0; i < q;i++)
        {
            cin >> x[i];
        }
        long long pre = LLONG_MAX;
        for (long long i = 0; i < q;i++)
        {
            if(pre<=x[i])
            {
                continue;
            }
            long long val = 1 << x[i];
            for (long long k = 0; k < n;k++)
            {
                if(v[k]%val==0)
                {
                    v[k] += (1 << (x[i] - 1));
                }
            }
            pre = x[i];
        }
        for(long long i:v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}