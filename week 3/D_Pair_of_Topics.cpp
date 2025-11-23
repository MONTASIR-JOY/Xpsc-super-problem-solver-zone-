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
    vector<long long> a(n);
    vector<long long> b(n);
    for (long long i = 0; i < n;i++)
    {
        cin >> a[i];
    }
    for (long long i = 0; i < n;i++)
    {
        cin >> b[i];
    }

    pbds<long long> p;
    long long cnt = 0;
    for (long long i = 0; i < n;i++)
    {
        long long dif = a[i] - b[i];
        //cout << dif << " -> ";
        
        cnt += i-p.order_of_key(-dif+1);
        // cout << i-p.order_of_key(-dif+1) << endl;
        p.insert(dif);
    }
    cout << cnt << endl;
    return 0;
}