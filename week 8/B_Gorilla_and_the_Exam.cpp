#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;
    while (t--)
    {
        long long n, k;
        cin >> n >> k;
        vector<long long> v(n);
        map<long long, long long> mp;
        for (long long i = 0; i < n; i++)
        {
            cin >> v[i];
            mp[v[i]]++;
        }

        vector<long long> vec;

        for (auto i : mp)
        {
            vec.push_back(i.second);
        }

        sort(vec.begin(), vec.end());
        long long cnt=0;
        for(auto i:vec)
        {
            if(k>=i)
            {
                k-=i;

            }
            else cnt ++;
        }
        cout<<((cnt==0)?1:cnt)<<endl;
    }
    return 0;
}
