#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;

    while(t--)
    {
        long long n, k;
        cin >> n >> k;

        if (n * n - 1 == k)
        {
            cout << "NO" << endl;
            continue;
        }

        cout << "YES" << endl;  

        long long count = k;
        char ans[n][n];

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                if (count > 0)
                {
                    ans[i][j] = 'U';
                    count--;
                }
                else
                {
                    if (i != n - 1)
                    {
                        ans[i][j] = 'D';
                    }
                    else
                    {
                        if (j == n - 1)
                        {
                            ans[i][j] = 'L';
                        }
                        else
                        {
                            ans[i][j] = 'R';
                        }
                    }
                }
            }
        }

        for (long long i = 0; i < n; i++)
        {
            for (long long j = 0; j < n; j++)
            {
                cout << ans[i][j];
            }
            cout << endl;
        }
    }

    return 0;
}
