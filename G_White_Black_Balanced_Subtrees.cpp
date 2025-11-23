#include<bits/stdc++.h>
using namespace std;
const int mx = 4e3 + 5;

vector<int> g[mx];
vector<int> white(mx);
vector<int> black(mx);
string s;

void dfs(int src)
{
    if(s[src]=='W')
    {
        white[src]++;
    }
    else{
        black[src]++;
    }
    for (int child : g[src])
    {
        dfs(child);
        white[src] += white[child];
        black[src] += black[child];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        
        int n;
        cin >> n;
        for (int i = 0; i < n+5;i++)
        {
            g[i].clear();
        }
        for (int i = 0; i < n + 5; i++)
        {
            white[i] = 0;
        }
        for (int i = 0; i < n+5;i++)
        {
            black[i] = 0;
        }
        for (int i = 2; i <= n; i++)
        {
            int x;
            cin >> x;
            g[x].push_back(i);
        }
        cin >> s;
        s = " " + s;
        dfs(1);
        int ans = 0;
        for (int i = 1; i <= n;i++)
        {
            if(white[i]==black[i])
            {
                ans++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}