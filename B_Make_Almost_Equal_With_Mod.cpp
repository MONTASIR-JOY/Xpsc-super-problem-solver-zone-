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
        vector<long long>v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        long long ans = 0;

        for (long long i = 0; i < 65;i++)
        {
            long long k = 1LL << i;
            set<long long> s;
            for (long long j = 0; j < n;j++)
            {
                s.insert(v[j] % k);
            }
            if(s.size()==2)
            {
                ans = k;
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}