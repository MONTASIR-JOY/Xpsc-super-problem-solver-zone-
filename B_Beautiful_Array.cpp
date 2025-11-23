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
        long long n, k, b, s;
        cin >> n >> k >> b >> s;

        long long mn = k*b;
        long long mx = k * b + n * (k - 1);
        //cout << mn << " " << mx << endl;
        if(s<mn || s>mx)
        {
            cout << -1 << endl;
            continue;
        }

        vector<long long> ans;
        ans.push_back(mn);
        long long rem = s - mn;
        for (long long i = 1; i < n;i++)
        {
            if(rem==0)
            {
                ans.push_back(0);
                continue;
            }
            ans.push_back(min(rem,k-1));
            rem -= min(rem, k - 1);
        }
        if(rem>0)
        {
            ans[0] += rem;
        }
        for(long long i:ans)
        {
            cout << i << " ";
        }
        cout<<endl;
    }
    return 0;
}