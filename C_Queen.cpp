#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<long long> ans;
    vector<long long> g[n + 1];
    vector<long long> bad_child(n + 1);
    vector<long long> respect(n + 1);
    long long root = -1;
    for (long long i = 1; i <= n;i++)
    {
        long long a, b;
        cin >> a >> b;
        if(a!=-1)
        {
            g[a].push_back(i);
        }
        if(a==-1)
        {
            root = i;
        }
        if(b==1)
        {
            bad_child[a]++;
            respect[i] = 1;
        }
    }

    for (long long i = 1; i <= n;i++)
    {
        if(i==root)
        {
            continue;
        }

        if(bad_child[i]==g[i].size() && respect[i]==1)
        {
            ans.push_back(i);
        }
    }
    if(ans.size()==0)
    {
        cout << -1 << endl;
    }
    else
    {
        for(long long i:ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
        return 0;
}