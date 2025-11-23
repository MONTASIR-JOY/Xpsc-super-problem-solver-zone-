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
        long long n, l, r;
        cin >> n >> l >> r;
        map<long long, long long> mp;
        vector<long long> ans(n + 2);
        bool x = true;
        for (long long i = 1; i <= n;i++)
        {
            long long cnt = l / i;
            if(l%i!=0)
            {
                cnt++;
            }
            long long ai = cnt * i;
            if(ai<l || ai>r)
            {
                x = false;
            }
            ans[i] = ai;
        }
        if(x==false)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            for (long long i = 1; i <= n;i++)
            {
                cout << ans[i] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}