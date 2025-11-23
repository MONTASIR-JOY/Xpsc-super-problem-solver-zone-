#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n, l, r, k;
        cin >> n >> l >> r >> k;
        if(n%2==1)
        {
            cout << l << endl;
            continue;
        }
        long long left = 64 - __builtin_clzll(l);
        long long right = 64 - __builtin_clzll(r);
        if(left==right || n<4)
        {
            cout << -1 << endl;
            continue;
        }
        long long f = (1 << left);
        if(k==n || k==n-1)
        {
            cout << f << endl;
        }
        else
        {
            cout << l << endl;
        }
    }
    return 0;
}