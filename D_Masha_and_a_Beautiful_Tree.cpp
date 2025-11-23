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
        vector<long long> v(n+1);
        v[0] = 0;
        for (long long i = 1; i <= n;i++)
        {
            cin >> v[i];
        }
       
        bool ans = true;
        long long cnt = 0;
        for (long long i = 2; i <= n; i*=2)
        {
            for (long long j = 1; j <= n-i/2;j+=i)
            {
                if((j+i/2)<=n && v[j]>v[j+i/2]) 
                {
                    long long point = j + i / 2;
                    for (long long k = j; k < j + i / 2;k++)
                    {
                        swap(v[k], v[point]);
                        point++;
                    }
                    cnt++;
                }
            }
        }

        long long p = 1;
        for (long long i = 1; i <= n;i++)
        {
            //cout << v[i] << " ";
            if(v[i]!=p)
            {
                ans = false;
                break;
            }
            p++;
        }
        if(ans==false)
        {
            cout << -1 << endl;
        }
        else{
            cout << cnt << endl;
        }
    }
    return 0;
}