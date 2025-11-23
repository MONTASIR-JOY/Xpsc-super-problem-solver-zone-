#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long t;
    cin>>t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        long long a[n][n];
        long long b[n][n];

        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < n;j++)
            {
                cin >> a[i][j];
                b[n-j-1][n-i-1] = a[i][j];
            }
        }

        long long cnt = 0;
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < n;j++)
            {
                if(a[i][j]!=b[j][i])
                {
                    cnt++;
                }
                //cout << b[j][i] << " ";
            }
            //cout << endl;
        }
        if(cnt/2>k)
        {
            cout << "NO" << endl;
        }
        else
        {
            if((cnt/2-k)%2==0)
            {
                cout << "YES" << endl;
            }
            else
            {
                if(n%2==0)
                {
                    cout << "NO" << endl;
                }
                else
                {
                    cout << "YES" << endl;
                }
            }
        }
    }
    return 0;
}