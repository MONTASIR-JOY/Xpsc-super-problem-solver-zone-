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
        long long n, m, k;
        cin >> n >> m >> k;

        char s[n + 2][m + 2];
        long long pre[n + 2][m + 2];
        memset(pre, 0, sizeof(pre));

        long long sum = 0;
        long long ans = 0;

        for(long long i = 1; i <= n; i++)
        {
            for(long long j = 1; j <= m; j++)
            {
                cin >> s[i][j];
                if(s[i][j]=='g')
                {
                    pre[i][j] = 1;
                    sum++;
                }
            }
        }

        for(long long i = 1; i <= n; i++)
        {
            for(long long j = 1; j <= m; j++)
            {
                pre[i][j] += pre[i][j - 1];
                pre[i][j] += pre[i - 1][j];
                pre[i][j] -= pre[i - 1][j - 1];
            }
        }

        for(long long i = 1; i <= n; i++)
        {
            for(long long j = 1; j <= m; j++)
            {
                if(s[i][j] == '.')
                {
                    long long mxx = min(i + k - 1, n);
                    long long mnx = max(1LL, i - k + 1) - 1;
                    long long mxy = min(m, j + k - 1);
                    long long mny = max(1LL, j - k + 1) - 1;
                    long long ache = pre[mxx][mxy] - pre[mxx][mny] - pre[mnx][mxy] + pre[mnx][mny];
                    ans = max(ans, sum - ache);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}