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
        vector<long long> v(n);
        pbds<long long> p;
        pbds<long long> s;
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            p.insert(v[i]);
        }

        p.erase(v[0]);
        s.insert(v[0]);

        for (long long i = 1; i < n - 1;i++)
        {
            p.erase(v[i]);
            long long age=i-s.order_of_key(v[i]);
            long long pore = p.size() - p.order_of_key(v[i]);
            s.insert(v[i]);
            ans += min(age, pore);
        }
        cout << ans << endl;
    }
    return 0;
}
