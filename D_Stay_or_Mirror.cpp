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

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        int mn = INT_MAX;
        for (int i = 0; i < n / 2;i++)
        {
            if(v[i]<=2*n-v[i])
            {
                v[i] = 2 * n - v[i];
            }
            mn = min(mn, v[i]);
        }
        for (int i = n/2; i <n;i++)
        {
            if(v[i]>=2*n-v[i] && mn>(2*n-v[i]))
            {
                v[i] = 2 * n - v[i];
            }
        }

        int ans = 0;
        pbds<int> p;
        for (int i = 0; i < n;i++)
        {
            p.insert(v[i]);
            ans += p.order_of_key(v[i]);
            cout << v[i] << " ";
        }
        cout << ans << endl;
        // int l = max(n / 2 - 1, 0);
        // int r = min(n - 1, n / 2 + 1);
        // for (int i = l; i <= r;i++)
        // {

        // }
    }
    return 0;
}