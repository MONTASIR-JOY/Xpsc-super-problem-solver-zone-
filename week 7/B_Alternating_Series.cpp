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
        vector<long long> ans;
        if(n%2==0)
        {
            for (long long i = 0; i < n - 2;i++)
            {
                if(i%2==0)
                {
                    cout << -1 << " ";
                }
                else{
                    cout << 3 << " ";
                }
            }
            cout << -1 << " "<< 2 << endl;
        }
        else{
            for (long long i = 0; i < n;i++)
            {
                if(i%2==0)
                {
                    cout << -1 << " ";
                }
                else{
                    cout << 3 << " ";
                }
            }
        }
    }
    return 0;
}