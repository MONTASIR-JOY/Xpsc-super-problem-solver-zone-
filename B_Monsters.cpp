#include<bits/stdc++.h>
using namespace std;
bool cmp(pair<long long,long long>a,pair<long long,long long>b)
{
    if(a.first>=b.first)
    {
        if(a.first==b.first)
        {
            return a.second < b.second;
        }
        else{
            return true;
        }
    }
    return false;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while(t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> ans;
        vector<pair<long long, long long>> v;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            if(x%k==0)
            {
                ans.push_back(i + 1);
                continue;
            }
            v.push_back({x % k, i + 1});
        }

        sort(v.begin(), v.end(), cmp);
        for (long long i = 0;i<v.size();i++)
        {
            ans.push_back(v[i].second);
        }
        for(long long i:ans)
        {
            cout << i << " ";
        }
        cout<<endl;
    }
    return 0;
}