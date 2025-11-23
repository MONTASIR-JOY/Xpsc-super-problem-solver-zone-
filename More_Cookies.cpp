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
        long long n, c;
        cin >> n >> c;
        vector<long long> v(n);
        set<long long> s;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        sort(v.begin(), v.end());
        long long mn = c;
        if(mn<=v[0])
        {
            mn = max(mn,v[0]);
        }
        for(long long i:s)
        {
            if(mn==i && i>=c)
            {
                mn++;
            }
        }
        cout << mn-c << endl;
    }
    return 0;
}