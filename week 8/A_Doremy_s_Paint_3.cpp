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
        map<long long,long long> mp;
        set<long long> s;

        for (long long i = 0; i < n;i++)
        {
            long long x;
            cin >> x;
            mp[x]++;
            s.insert(x);
        }
        if(mp.size()>2)
        {
            cout << "No" << endl;
        }
        else if(mp.size()==1)
        {
            cout << "Yes" << endl;
        }
        else
        {
            long long x, y;
            x = mp[*s.begin()];
            y = mp[*s.rbegin()];
            if(abs(x-y)<=1)
            {
                cout << "Yes" << endl;
            }
            else{
                cout << "No" << endl;
            }
        }
    }
    return 0;
}