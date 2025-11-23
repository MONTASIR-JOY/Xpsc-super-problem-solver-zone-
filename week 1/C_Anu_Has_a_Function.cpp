#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    
    vector<long long> v(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<long long> bits(60, 0);
    for (long long i = 0; i < n; i++)
    {
        for (long long k = 0; k < 60; k++)
        {
            if ((v[i] >> k) & 1)
            {
                bits[k]++;
            }
        }
    }

    long long first = v[0];
    long long o = -1, idx = 0;
    for (long long i = 0; i < n; i++)
    {
        long long curr = 0;
        for (long long k = 0; k < 60; k++)
        {
            if (((v[i] >> k) & 1) && bits[k] == 1)
            {
                curr += (1LL << k);
            }
        }
        if (curr > o)
        {
            o = curr;
            first = v[i];
            idx = i;
        }
    }

    cout << first << " ";
    for (long long i = 0; i < n; i++)
    {
        if (i == idx) continue;
        cout << v[i] << " ";
    }
    cout << endl;
    return 0;
}