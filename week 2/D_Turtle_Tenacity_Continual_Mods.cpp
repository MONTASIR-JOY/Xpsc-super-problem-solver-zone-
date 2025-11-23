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
        long long mn = LLONG_MAX;
        long long mncnt = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mn = min(mn, v[i]);
        }
        for(long long i:v)
        {
            if(i==mn)
            {
                mncnt++;
            }
        }

        if(mncnt==1)
        {
            cout << "YES" << endl;
            continue;
        }
        bool x = false;
        for(long long i:v)
        {
            if(i==mn)
            {
                continue;
            }
            if(mn!=1)
            {
                if(i%mn<mn && i%mn!=0)
                {
                    x = true;
                    break;
                }
            }
        }
        if(x)
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