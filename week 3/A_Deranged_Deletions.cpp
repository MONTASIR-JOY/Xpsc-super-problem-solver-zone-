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
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<long long> a = v;
        sort(a.begin(), a.end());
        vector<long long> ans;
        for (long long i = 0; i < n;i++)
        {
            if(a[i]!=v[i])
            {
                ans.push_back(v[i]);
            }
        }
        if(ans.size()==0)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        cout << ans.size() << endl;

        for(long long i:ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}