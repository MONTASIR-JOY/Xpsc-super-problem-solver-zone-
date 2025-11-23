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
        if(v[0]==1)
        {
            v[0]++;
        }
        for (long long i = 1;i<n;i++)
        {
            if(v[i]==1)
            {
                v[i]++;
            }
            if(v[i]%v[i-1]==0)
            {
                v[i]++;
                if(v[i]%v[i-1]==0)
                {
                    v[i]++;
                }
            }
        }
        for(long long i:v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}