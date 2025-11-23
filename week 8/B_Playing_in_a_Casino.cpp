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
        long long n, m;
        cin >> n >> m;
        long long ans = 0;
        vector<vector<int>> v(m, vector<int> (n));
        long long mat1[n][m];
        long long mat[m][n];
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < m;j++)
            {
                cin >> mat1[i][j];
                mat[j][i] = mat1[i][j];
            }
        }

        for (long long i = 0; i < m;i++)
        {
            vector<long long> v;
            for (long long j = 0; j < n;j++)
            {
                v.push_back(mat[i][j]);
            }
            // for (long long j = 0; j < n;j++)
            // {
            //     cout << v[j] << " ";
            // }
            // cout << endl;
            sort(v.begin(), v.end());
            long long sum = 0;
            vector<long long> pref(n);
            pref[0]=v[0];
            for (long long k = 1; k < n;k++)
            {
                pref[k] = pref[k - 1] + v[k];
            }
            for (long long k = 1; k < n; k++)
            {
                sum += (k * v[k] - pref[k - 1]);
            }
            ans += sum;
        }
        cout << ans << endl;
    }
    return 0;
}