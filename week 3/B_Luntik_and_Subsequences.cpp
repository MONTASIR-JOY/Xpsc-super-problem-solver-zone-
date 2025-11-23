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
        long long z = 0;
        long long o = 0;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]==0)
            {
                z++;
            }
            if(v[i]==1)
            {
                o++;
            }
        }
        z = pow(2, z);
        cout << o * z << endl;
    }
    return 0;
}