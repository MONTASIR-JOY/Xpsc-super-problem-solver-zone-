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
        long long n;
        cin >> n;
        vector<long long>v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        bool ans = true;
        for (long long i = 1; i < __lg(n);i++)
        {
            long long j = 1 << i;
            long long s = 1 << (i + 1);
            //cout << j << " " << s << endl;
            for (long long k = j+1; k < s;k++)
            {
                if(v[k-1]>v[k])
                {
                    ans = false;
                    break;
                }
            }
            if(ans==false)
            {
                break;
            }
        }
        long long j = 1 << __lg(n);
        for (long long i = j+1; i < n;i++)
        {
            if(v[i-1]>v[i])
            {
                ans = false;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}