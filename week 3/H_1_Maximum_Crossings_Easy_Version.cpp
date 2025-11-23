#include <bits/stdc++.h>

#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

using namespace std;

template <typename T> using pbds = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;

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
        pbds<long long> p;
        long long cnt = 0;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            p.insert(x);
            cnt += (i - p.order_of_key(x));
            cout << x << " " << p.order_of_key(x) << endl;
        }
        cout << cnt << endl;
    }
    return 0;
}
