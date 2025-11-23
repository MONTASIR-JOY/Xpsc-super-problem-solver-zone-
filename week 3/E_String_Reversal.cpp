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

    long long n;
    cin >> n;
    string s;
    cin >> s;
    string r = s;
    reverse(r.begin(), r.end());

    map<char, vector<long long>> pos_s, pos_r;
    for (long long i = 0; i < n; i++) 
    {
        pos_s[s[i]].push_back(i);
        pos_r[r[i]].push_back(i);
    }

    vector<long long> permutation(n);
    for (char ch = 'a'; ch <= 'z'; ch++) 
    {
        for (long long i = 0; i < pos_s[ch].size(); i++) 
        {
            permutation[pos_r[ch][i]] = pos_s[ch][i];
        }
    }

    pbds<long long> p;
    long long ans = 0;
    for (long long i = n - 1; i >= 0; i--)
    {
        ans += p.order_of_key(permutation[i]);
        p.insert(permutation[i]);
    }
    cout << ans << endl;
    return 0;
}