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
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        bool ans = true;
        bool one = false;
        // for (long long i = 0; i < n;i++)
        // {
        //     if(v[i]==1)
        //     {
        //         one = true;
        //     }
        //     if(one)
        //     {
        //         if(v[i]>1)
        //         {
        //             ans = false;
        //         }
        //     }
        // }

        // if(ans)
        // {
        //     cout << "NO" << endl;
        //     continue;
        // }
        long long mn = v[0];
        ans = true;
        for (long long i = 0; i < n;i++)
        {
            
            if((2*mn)<=v[i])
            {
                ans = false;
                break;
            }
            mn=min(mn,v[i]);
            //cout << 2*mn << " " << v[i] << " ";
        }
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