#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        long long st = 1;
        long long ed = n;
        for (long long i = 1; i <= n; i++)
        {
            if (i % k == 0)
            {
                cout << st << " ";
                st++;
            }
            else
            {
                cout << ed << " ";
                ed--;
            }
        }
        cout << endl;
    }
    return 0;
}
