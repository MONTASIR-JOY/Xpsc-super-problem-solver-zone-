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
        string a, b;
        cin >> a >> b;
        long long n = a.size();
        long long m = b.size();
        long long ans = 0;
        for (long long i = 0; i < n;i++)
        {
            for (long long j = 0; j < m;j++)
            {
                long long p = i;
                long long q = j;
                while(p<n && q<m)
                {
                    if(a[p]!=b[q])
                    {
                        break;
                    }
                    p++;
                    q++;
                }
                ans = max(ans, p-i);
            }
        }
        cout << n + m - 2 * ans << endl;
    }
    return 0;
}