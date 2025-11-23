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
        if(v[n-1]<v[n-2])
        {
            cout << "-1" << endl;
            continue;
        }
        if(v[n-1]<0 && v[n-2]<0)
        {
            if(!is_sorted(v.begin(),v.end()))
            {
                cout<< -1 << endl;
            }
            else
            {
                cout << 0 << endl;
            }
            continue;
        }
        cout << n-2 << endl;
        for (long long i = 0; i < n;i++)
        {
            if(i<n-2)
            {
                v[i] = v[n - 2] - v[n - 1];
                cout << i + 1 << " " << n - 1 << " " << n << endl;
            }
            else
            {
                continue;
            }
        }
        // for(long long i:v)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
    }
    return 0;
}