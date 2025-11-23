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

    int n;
    cin >> n;
    pbds<int> p;
    for (int i = 0; i < n;i++)
    {
        int x;
        cin >> x;
        p.insert(x);
    }
    // int x=p.order_of_key(4);
    // cout << x << endl;

    auto it = p.find_by_order(1);
    cout << *it << endl;

    p.erase(4);
    for (int i:p)
    {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}