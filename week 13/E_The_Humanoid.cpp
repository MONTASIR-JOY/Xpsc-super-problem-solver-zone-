#include <bits/stdc++.h>
using namespace std;

const long long mxn = 2e6 + 9;
vector<long long> v(mxn);
long long n;
long long f(long long i,long long h,long long g,long long b)
{
    if(i==n)
    {
        return 0;
    }

    if(v[i]<h)
    {
        return 1 + f(i + 1, h + (v[i] / 2), g, b);
    }
    long long ans1 = (g ? f(i, 2 * h, g - 1, b) : 0);
    long long ans2 = (b ? f(i, 3 * h, g, b - 1) : 0);
    return max(ans1, ans2);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long h;
        cin >> n >> h;
        
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.begin() + n);
        cout << f(0, h, 2, 1) << endl;
    }
    return 0;
}