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
        long long a, b, k;
        cin >> a >> b >> k;
        if(a==0 && b==0)
        {
            cout << 0 << endl;
            continue;
        }
        if(a==0 || b==0)
        {
            cout << 1 << endl;
            continue;
        }
        long long gcd = __gcd(a, b);
        long long dupa = a / gcd;
        long long dupb = b / gcd;

        if(dupa<=k && dupb<=k)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}