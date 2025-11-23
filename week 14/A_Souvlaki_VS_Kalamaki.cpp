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
        bool f = true;
        for (long long i = 1; i < n-1;i++)
        {
            if(i%2==1 && v[i]!=v[i+1])
            {
                f = false;
                break;
            }
        }
        cout << (f ? "YES" : "NO") << endl;
    }
    return 0;
}