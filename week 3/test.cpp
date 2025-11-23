#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    vector<int> v(n+1);
    for (int i = 1; i <= n;i++)
    {
        cin >> v[i];
    }
    vector<int> d(n + 2), pref(n + 2);
    d[0] = 0;
    pref[0] = 0;
    for (int i = 1; i <= q; i++)
    {
        int l, r, x;
        cin >> l >> r >> x;
        d[l] += x;
        d[r+1] -= x;
    }
    for (int i = 1; i <= n + 1;i++)
    {
        pref[i] = pref[i-1] + d[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cout << v[i] + pref[i]<< " ";
    }
    cout << endl;
    return 0;
}