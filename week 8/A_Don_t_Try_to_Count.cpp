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
        string a;
        cin >> a;
        string ans;
        for (long long i = 0; i < 100;i++)
        {
            ans.append(a);
        }
        string b;
        cin >> b;
        long long cnt = -1;
        bool found = false;
        for (long long i = m; i < ans.size();i++)
        {
            bool x = true;
            long long trc = i-m;
            for (long long j = 0; j < m;j++)
            {
                if(ans[trc]!=b[j])
                {
                    x = false;
                    break;
                }
                trc++;
            }
            if(x)
            {
                cnt = trc;
                found = true;
                break;
            }
        }
        long long final = 0;
        long long num = n;
        if(found==false)
        {
            cout << -1 << endl;
            continue;
        }
        while(cnt>num)
        {
            num *= 2;
            final++;
        }
        cout << final << endl;
    }
    return 0;
}