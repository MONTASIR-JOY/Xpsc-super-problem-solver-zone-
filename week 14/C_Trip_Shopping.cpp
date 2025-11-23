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
        long long n, k;
        cin >> n >> k;
        vector<long long> a(n);
        vector<long long> b(n);
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        vector<pair<long long, long long>> combine;
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
            ans += abs(a[i] - b[i]);
            if(a[i]>b[i])
            {
                swap(a[i], b[i]);
            }
            combine.push_back({a[i], b[i]});
        }

        sort(combine.begin(), combine.end());
        bool cut = false;
        long long mn = combine[0].second;
        for (long long i = 1; i < n;i++)
        {
            if(combine[i-1].second>=combine[i].first)
            {
                cut = true;
                break;
            }
        }
        if(cut)
        {
            cout << ans << endl;
            continue;
        }

        mn = LLONG_MAX;
        for (long long i = 1; i < n;i++)
        {
            mn = min(mn, abs(combine[i - 1].second - combine[i].first));
        }
        cout << ans + 2 * mn << endl;
    }
    return 0;
}