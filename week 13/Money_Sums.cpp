#include<bits/stdc++.h>
using namespace std;

const long long mxn = 1e2 + 9, m = 1e5 + 9;
long long n;
bool dp[mxn][m];
vector<long long> v(mxn);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    cin >> n;
    long long sum = 0;
    for (long long i = 1; i <= n; i++)
    {
        cin >> v[i];
        sum += v[i];
    }
    for (long long i = 0; i <= n; i++)
    {
        for (long long j = 0; j <= sum; j++)
        {
            dp[i][j] = false;
        }
    }

    dp[0][0] = true;

    for (long long i = 1; i <= n; i++)
    {
        for (long long j = 0; j <= sum; j++)
        {
            dp[i][j] = dp[i-1][j];
            
            if (j >= v[i] && dp[i-1][j - v[i]])
            {
                dp[i][j] = true;
            }
        }
    }
    
    vector<long long> ans;
    for (long long j = 1; j <= sum; j++)
    {
        if (dp[n][j])
        {
            ans.push_back(j);
        }
    }

    sort(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(long long i : ans)
    {
        cout << i << " ";
    }
    cout << endl;
    
    return 0;
}