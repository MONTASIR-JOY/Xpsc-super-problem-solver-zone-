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
        long long n;
        cin >> n;
        double a, b, c, d;
        cin >> a >> b >> c >> d;

        double dis = sqrtl((a - c) * (a - c) + (b - d) * (b - d));
        double sum = dis;
        double mx = dis;
        for (long long i = 0; i < n;i++)
        {
            double x;
            cin >> x;
            sum += x;
            mx = max(x, mx);
        }
        sum -= mx;
        if(sum>=mx)
        {
            cout << "Yes" << endl;
        }
        else{

            cout << "No" << endl;
        }
    }
    return 0;
}