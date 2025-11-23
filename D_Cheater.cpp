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

        vector<long long>a(n);
        vector<long long>b(n);
        set<long long> s;

        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
            s.insert(a[i]);
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }

        long long mnb = LLONG_MAX;
        long long mxa = 0;
        bool ans = false;

        for(long long i = 0, j = n - 1; i < n; i++, j--)
        {
            mnb = min(mnb, b[i]);
    
            if(*s.begin()>mnb)
            {
                cout << n - i << endl;
                ans = true;
                break;
            }
    
            if(s.size()==1 && mxa>mnb)
            {
                cout << n - i << endl;
                ans = true;
                break;
            }
    
            if(s.size()>1 && mxa>mnb)
            {
                auto it = s.begin();
                it++;
                if(*it>mnb)
                {
                    cout << n - i << endl;
                    ans = true;
                    break;
                }
            }
    
            s.erase(a[j]);
            mxa = max(mxa, a[j]);
        }

        if(!ans)
        {
            cout << 0 << endl;
        }
    }
    return 0;
}