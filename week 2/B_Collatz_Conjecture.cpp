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

        while (k > 0 && x!= 1)
        {
            long long rem = y - x % y;

            if (rem >= k)
            {
                x += k;
                k = 0;
            }
            else
            {
                x += rem;
                k -= rem;
            }
            while (x % y == 0)
            {
                x /= y;
            }
        }

        if (k > 0)
        {
            k %= y - 1;
            x += k;
            while (x % y == 0)
            {
                x /= y;
            }
        }
        cout << x << endl;
    }
    return 0;
}