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
        long long a, b;
        cin >> a >> b;
        if(a==0)
        {
            cout << 0 << endl;
            continue;
        }

        long long lastb = b;
        long long ans = LLONG_MAX;

        for (long long i = b; i <= b + 100000;i++)
        {
            long long op = i - b;
            if(i==1)
            {
                i++;
                op++;
            }
            long long dupa = a;
            while(dupa)
            {
                dupa /= i;
                op++;
            }
            ans = min(ans, op);
        }
        cout << ans << endl;
    }
    return 0;
}