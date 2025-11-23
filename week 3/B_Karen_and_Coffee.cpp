#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k, q;
    cin >> n >> k >> q;
    map<long long, long long> mp;
    for (long long i = 0; i < n; i++)
    {
        long long l, r;
        cin >> l >> r;

        mp[l]++;
        mp[r + 1]--;
    }

    long long sum = 0;
    map<long long, long long> v;
    long long mx = LLONG_MIN;
    long long i = 0;
    long long mn;
    for (auto val : mp)
    {
        if (i == 0)
        {
            mn = val.first;
            i++;
        }
        sum += val.second;
        v[val.first] = sum;
        mx = max(mx, val.first);
    }

    vector<long long> range(200005, 0);
    long long l = mn;
    long long r = mn;
    long long cur = v[l];

    while (r <= mx)
    {
        if (v.find(r) != v.end())
        {
            cur = v[r];
        }
        range[r] = cur;
        r++;
    }
    for (long long i = 0; i < 200005;i++)
    {
        if(range[i]>=k)
        {
            range[i] = 1;
        }
        else {
            range[i] = 0;
        }
    }

    vector<long long> pre(200005);
    pre[0] = range[0];
    for (long long i = 1; i < pre.size();i++)
    {
        pre[i] = pre[i - 1] + range[i];
    }
    while (q--)
    {
        long long l, r;
        cin >> l >> r;
        cout << pre[r] - pre[l-1] << endl;
    }
    return 0;
}