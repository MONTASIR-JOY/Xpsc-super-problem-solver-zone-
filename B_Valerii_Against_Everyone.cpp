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
        set<long long> s;
        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            s.insert(x);
        }
        if(s.size()==n)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}