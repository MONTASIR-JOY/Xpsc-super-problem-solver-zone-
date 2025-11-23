// ar ki optimize korbo.. laga submit...ekhon hoile tho
#include<bits/stdc++.h>
using namespace std;
set<long long> s;
map<long long,long long> pr;
bool prime(long long n)
{
    for (long long i = 2; i * i <= n;i++)
    {
        if(n%i==0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    for (long long i = 2; i <= 1e6;i++)
    {
        if(prime(i))
        {
            pr[i] = 1;
        }
    }

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        vector<long long> v(n);
        long long one = 0;
        long long two = 0;
        map<long long, long long> mp1;
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            mp1[v[i] + 1]++;
            if(v[i]%2==0)
            {
                two++;
            }
            else{
                one++;
            }
        }
        long long id;
        for (long long i = 0; i < n;i++)
        {
            cin >> id;
            //cout << id << " ";
        }
        long long gcd = 0;
        map<long long,long long> mp;
        map<long long,long long> mp2;
        vector<long long> p;
        for (long long i = 0;i<n;i++)
        {
            long long num = v[i];
            long long mod = 2;
            if(pr[num]==1)
            {
                mp[num]++;
                p.push_back(num);
                continue;
            }
            while(num>mod)
            {
                if(num%mod==0)
                {
                    mp[mod]++;
                    while(num%mod==0)
                    {
                        num /= mod;
                    }
                }
                mod++;
                if(pr[num])
                {
                    break;
                }
            }
            if(num>1)
            {
                mp[num]++;
            }
        }
        for (long long i = 0;i<n;i++)
        {
            long long num = v[i]+1;
            long long mod = 2;
            if(pr[num]==1)
            {
                mp2[num]++;
                p.push_back(num);
                continue;
            }
            while(num>mod)
            {
                if(num%mod==0)
                {
                    mp2[mod]++;
                    while(num%mod==0)
                    {
                        num /= mod;
                    }
                }
                mod++;
                if(pr[num])
                {
                    break;
                }
            }
            if(num>1)
            {
                mp2[num]++;
            }
        }
        bool ans=false;
        for(auto i:mp)
        {
            // cout << i.first << " " << i.second << endl;
            if(i.second>1)
            {
                ans = true;
                break;
            }
        }
        if(ans==true)
        {
            cout << 0 << endl;
            continue;
        }
        bool x = false;
        for (auto i:mp)
        {
            long long pime=i.first;
            if(mp2[pime]>=1)
            {
                x = true;
            }
        }
        if ((one >= 1 && two >= 1) || x)
        {
            cout << 1 << endl;
            //cout << one << two << endl;
        }
        else
        {
            cout << 2 << endl;
        }
    }
    return 0;
}