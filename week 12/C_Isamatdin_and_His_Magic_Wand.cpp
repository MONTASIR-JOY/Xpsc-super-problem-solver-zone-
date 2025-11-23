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
        bool odd = false;
        bool even = false;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]%2==1)
            {
                odd = true;
            }
            else{
                even = true;
            }
        }
        if(even==true && odd==true)
        {
            sort(v.begin(), v.end());
            for(long long i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            for(long long i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}