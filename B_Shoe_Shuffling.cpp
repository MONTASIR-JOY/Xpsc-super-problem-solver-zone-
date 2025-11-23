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
        long long mx = LLONG_MIN;
        map<long long, long long> freq;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            freq[v[i]]++;
        }
        bool check = true;
        for(auto i:freq)
        {
            if(i.second==1)
            {
                check = false;
                break;
            }
        }
        if(check==false)
        {
            cout << -1 << endl;
            continue;
        }
        
        vector<long long> ans(n);
        for (long long i = 0; i < n; i++)
        {
            ans[i] = i + 1;
        }

        long long l = 0;
        long long r = 0;
        while(r<n)
        {
            while(r < n && v[r]==v[l])
            {
                r++;
            }
            rotate(ans.begin() + l, ans.begin() + l + 1, ans.begin()+r);
            l = r;
        }
        for (long long i : ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}