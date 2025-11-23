#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b;
    cin >> a >> b;
    int ans = a;
    int extraa = 0;
    while(a>=b)
    {
        extraa++;
        a -= b;
        a++;
    }
    ans += extraa;
    cout << ans << endl;
    return 0;
}