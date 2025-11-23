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
        long long x, y, k;
        cin >> x >> y >> k;
        long long stick = k + k * y-1;
        long long op = (stick + x - 2) / ((x - 1));
        cout << op + k << endl;
    }
    return 0;
    
}