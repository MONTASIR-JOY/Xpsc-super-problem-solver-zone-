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
        long long n , s;
        cin >> n >> s;
        vector<long long> v(n);
        long long cnt1 = 0;
        long long cnt2 = 0;
        long long sum = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            sum += v[i];
            if(v[i]==1)
            {
                cnt1++;
            }
            if(v[i]==2)
            {
                cnt2++;
            }
        }
        long long cnt0 = n - cnt1 - cnt2;
        if(sum>s)
        {
            for(long long i:v)
            {
                cout << i << " ";
            }
            cout << endl;
            continue;
        }
        if(sum==s)
        {
            cout << -1 << endl;
            continue;
        }

        if(cnt1%2==1)
        {
            if(s!=sum+1)
            {
                cout << -1 << endl;
            }
            else{
                for (long long i = 0; i < cnt0;i++)
                {
                    cout << 0 << " ";
                }
                for (long long i = 0; i < cnt2;i++)
                {
                    cout << 2 << " ";
                }
                for (long long i = 0; i < cnt1;i++)
                {
                    cout << 1 << " ";
                }
                cout << endl;
            }
            continue;
        }
        else
        {
            if(s!=sum+1)
            {
                cout << -1 << endl;
            }
            else{
                for (long long i = 0; i < cnt0;i++)
                {
                    cout << 0 << " ";
                }
                for (long long i = 0; i < cnt2;i++)
                {
                    cout << 2 << " ";
                }
                for (long long i = 0; i < cnt1;i++)
                {
                    cout << 1 << " ";
                }
                cout << endl;
            }
            continue;
        }
    }
    return 0;
}