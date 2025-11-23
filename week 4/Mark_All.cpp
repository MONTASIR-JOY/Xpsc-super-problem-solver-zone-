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
        vector<long long> mids;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            if(i==0 ||i==n-1)
            {
                continue;
            }
            mids.push_back(v[i]);
        }
        if(n==1)
        {
            cout << v[0] << endl;
            continue;
        }
        long long m = min(v[0], v[n - 1]);
        sort(mids.begin(),mids.end());
        if(mids.size()>=2)
        {
            m = min(m, mids[0] + mids[1]);
        }
        cout << m << endl;
    }
    return 0;
}