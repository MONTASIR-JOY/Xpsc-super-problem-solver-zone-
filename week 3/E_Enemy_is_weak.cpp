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

    long long n;
    cin >> n;
    vector<long long> v(n);
    for (long long i = 0; i < n;i++)
    {
        cin >> v[i];
    }
    pbds<long long> p;
    pbds<long long> p1;
    
    vector<long long> left(n+1);
    vector<long long> right(n+1);
    for (long long i = 0; i < n;i++)
    {
        p.insert(v[i]);
        left[i] = i-p.order_of_key(v[i]);
    }

    for (long long i = n - 1; i >= 0;i--)
    {
        p1.insert(v[i]);
        right[i] = p1.order_of_key(v[i]);
    }
    long long ans = 0;
    for (long long i = 0; i < n;i++)
    {
        ans += left[i] * right[i];
    }

    cout << ans << endl;
    return 0;
}