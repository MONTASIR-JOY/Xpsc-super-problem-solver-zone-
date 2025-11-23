#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    long long n, m, q;
    cin >> n >> m >> q;
    vector<long long> v(n);

    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    vector<pair<pair<long long, long long>, long long>> op(m);

    for (long long i = 0; i < m; i++)
    {
        cin >> op[i].first.first >> op[i].first.second >> op[i].second;
    }

    vector<long long> diff(n + 2, 0);
    vector<long long> trc(m + 2, 0);

    for (long long i = 0; i < q; i++)
    {
        long long l, r;
        cin >> l >> r;
        trc[l]++;
        trc[r + 1]--;
    }

    for (long long i = 1; i <= m; i++)
    {
        trc[i] += trc[i - 1];
    }

    for (long long i = 0; i < m; i++)
    {
        op[i].second *= trc[i + 1];
        diff[op[i].first.first] += op[i].second;
        diff[op[i].first.second + 1] -= op[i].second;
    }

    for (long long i = 1; i <= n; i++)
    {
        diff[i] += diff[i - 1];
        cout << diff[i] + v[i - 1] << " ";
    }
    cout << endl;

    return 0;
}
