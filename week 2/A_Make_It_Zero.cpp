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
        for(long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        if(n%2==0)
        {
            cout << 2 << endl;
            cout << 1 << " " << n << endl;
            cout << 1 << " " << n << endl;
        }
        else{
            
            cout << 4 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << 1 << " " << n - 1 << endl;
            cout << n-1 << " " << n << endl;
            cout << n-1 << " " << n << endl;
        }
    }
    return 0;
}