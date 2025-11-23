#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        vector<pair<long long,long long>>v;
        for (long long i = 0; i < n;i++)
        {
            long long a, b;
            cin >> a >> b;
            v.push_back({a, b});
        }

        sort(v.begin(), v.end());
        pbds<long long> p;
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            p.insert(v[i].second);
            ans += i - p.order_of_key(v[i].second);
        }
        cout << ans << endl;
    }
    return 0;
}