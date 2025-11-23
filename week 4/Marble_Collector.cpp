#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        cin >> n >> m;
        map<int, int> mp;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        cout << m - mp.size() << endl;
    }
    return 0;
}