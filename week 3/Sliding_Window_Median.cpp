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

    long long n, k;
    cin >> n >> k;
    vector<long long> v(n);
    for (long long i = 0; i < n;i++)
    {
        cin >> v[i];
    }
    pbds<pair<long long, long long>> p;
    long long l = 0;
    long long r = 0;
    while(r<n)
    {
        p.insert({v[r], r});
        if(r-l+1==k)
        {
            long long mid = k / 2;
            if(k%2==0)
            {
                mid--;
            }
            auto ans = p.find_by_order(mid);
            cout << ans->first << " ";

            p.erase({v[l], l});
            l++;
        }
        r++;
    }
    return 0;
}