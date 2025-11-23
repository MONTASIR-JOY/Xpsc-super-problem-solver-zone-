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
        vector<long long>a(n), pref_er_vagses(n);
        long long sum = 0, lastz = -1;
        for(long long i=0; i<n; i++)
        {
            cin >> a[i];
            sum = (sum+a[i])%3;
            if(sum==0) lastz=i;

            pref_er_vagses[i] = sum;
        }

        if(lastz==-1)
        {
            cout << "Yes" << endl;
            continue;
        }

        if(lastz==n-1)
        {
            cout << "No" << endl;
            continue;
        }

        map<long long,long long>cnt;
        bool ok= false;

        for(long long i=0; i<n; i++)
        {
            if(i>lastz)
            {
                if(cnt[pref_er_vagses[i]] == 0)
                {
                    ok=true;
                    break;
                }
            }
            cnt[pref_er_vagses[i]]++;
        }

        if(ok)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        } 
    }
    return 0;
}