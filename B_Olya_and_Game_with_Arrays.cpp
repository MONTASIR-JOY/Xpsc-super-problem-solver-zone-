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
        long long n;
        cin >> n;
        vector<long long> a[n];
        vector<long long> second_min;
        vector<long long> first_min;
        long long first_min_min = LLONG_MAX;
        for (long long i = 0; i < n;i++)
        {
            long long m;
            cin >> m;
            for (long long j = 0; j < m;j++)
            {
                long long x;
                cin >> x;
                a[i].push_back(x);
            }
            sort(a[i].begin(), a[i].end());
            second_min.push_back(a[i][1]);
            first_min.push_back(a[i][0]);
            first_min_min = min(first_min_min, a[i][0]);
        }
        long long ans = 0;
        sort(second_min.begin(), second_min.end());
        for (long long i = 1; i < second_min.size();i++)
        {
            ans += second_min[i];
        }
        ans += first_min_min;
        cout << ans << endl;
    }
    return 0;
}