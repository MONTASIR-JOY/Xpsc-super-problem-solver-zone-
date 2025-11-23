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

        long long leftbitofl = __lg(l);
        long long leftbitofr = __lg(r);
        if(leftbitofl==leftbitofr || n==2)
        {
            cout << -1 << endl;
            continue;
        }

        r = (1LL << (leftbitofl + 1));
        if(k<n-1)
        {
            cout << l << endl;
        }
        else
        {
            cout << r << endl;
        }
    }
    return 0;
}