#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long double n;
    cin >> n;
    long double l = 0.5;
    long double r = 1e12;
    long double mid;
    long double ans;

    auto ok = [&](long double x)
    {
        return ((x * x + sqrt(x)) <= n);
    };
    for (int i = 0; i < 100;i++)
    {
        mid = l + (r - l) / 2.0;
        if(ok(mid))
        {
            ans = mid;
            l = mid;
        }
        else
        {
            r = mid;
        }
    }
    cout << fixed << setprecision(15) << ans << endl;
    return 0;
}