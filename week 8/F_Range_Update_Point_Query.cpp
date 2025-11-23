#include<bits/stdc++.h>
using namespace std;
int digitsum(int n)
{
    int sum = 0;
    while(n!=0)
    {
        sum += (n % 10);
        n /= 10;
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        set<int> s;
        for (int i = 0; i < n;i++)
        {
            if(v[i]>=10)
            {
                s.insert(i);
            }
        }

        while(m--)
        {
            int id;
            cin >> id;
            if(id==1)
            {
                int l, r;
                cin >> l >> r;
                l--;
                r--;
                if(s.empty())
                {
                    continue;
                }
                vector<int> remove;
                auto it = s.lower_bound(l);
                while(it!=s.end() && (*it)<=r)
                {
                    v[(*it)] = digitsum(v[(*it)]);
                    if(v[*it]<10)
                    {
                        remove.push_back((*it));
                    }
                    it++;
                }
                for(int i:remove)
                {
                    if(s.find(i)!=s.end())
                    {
                        s.erase(i);
                    }
                }
            }
            else{
                int x;
                cin >> x;
                x--;
                cout << v[x] << endl;
            }
        }
    }
    return 0;
}