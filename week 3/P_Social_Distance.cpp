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
        long long n, m;
        cin >> n >> m;
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.rbegin(), v.rend());
        v.push_back(v[0]);
        long long sum = 0;
        for (int i = 0; i < n;i++)
        {
            sum += max(v[i], v[i+1]);
        }
        if(n+sum<=m)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}