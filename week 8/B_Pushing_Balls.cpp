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
        long long mat[n][m];
        for (long long i = 0; i < n;i++)
        {
            string s;
            cin >> s;
            for (long long j = 0; j < m;j++)
            {
                if(s[j]=='1')
                {
                    mat[i][j] = 1;
                }
                else
                {
                    mat[i][j] = 0;
                }
            }
        }
        bool ans = true;
        long long ones = 0;
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < m;j++)
            {
                bool x = true;
                bool y = true;
                if(mat[i][j]==1)
                {
                    ones++;
                    long long cnt = 0;
                    for (long long k = 0; k < i;k++)
                    {
                        if(mat[k][j]==1)
                        {
                            cnt++;
                        }
                    }
                    if(cnt!=i)
                    {
                        x = false;
                    }
                    // cout << cnt << " ";
                    cnt = 0;
                    for (long long k = 0; k < j;k++)
                    {
                        if(mat[i][k]==1)
                        {
                            cnt++;
                        }
                    }
                    if(cnt!=j)
                    {
                        y = false;
                    }
                    if (!x && !y)
                    {
                        ans = false;
                        break;
                    }
                    // cout << cnt << endl;
                }
            }
            if(ans==false)
            {
                break;
            }
            
        }
        // cout << ones << endl;
        if(ans)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}