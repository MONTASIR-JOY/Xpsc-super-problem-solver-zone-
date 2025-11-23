#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long a, b, c;
    cin >> a >> b >> c;
    bool trg = false;
    a %= b;
    long long ans = -1;
    for (long long i = 0; i < 1e6;i++)
    {
        a *= 10;
        if(c==a/b)
        {
            ans = i + 1;
            break;
        }
        a %= b;
    }
    cout << ans << endl;
    return 0;
}