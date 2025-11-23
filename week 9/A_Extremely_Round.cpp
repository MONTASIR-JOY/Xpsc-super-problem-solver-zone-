#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        if(n<=9)
        {
            cout << n << endl;
            continue;
        }
        ans += 9;
        int mul = 10;
        while(n/mul!=0)
        {
            ans += min(9,(n / mul));
            mul *= 10;
        }
        cout << ans << endl;
    }
    return 0;
}