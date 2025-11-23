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
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        if(n==1)
        {
            if(v[0]!=1)
            {
                cout << "NO" << endl;
            }
            else{
                cout << "YES" << endl;
            }
            continue;
        }
        if(v[0]!=1)
        {
            cout << "NO" << endl;
            continue;
        }
        long long sum = 1;
        bool ans = true;
        for (long long i = 1; i < n;i++)
        {
            if(sum<v[i])
            {
                ans = false;
                break;
            }
            sum += v[i];
        }
        if(ans)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}