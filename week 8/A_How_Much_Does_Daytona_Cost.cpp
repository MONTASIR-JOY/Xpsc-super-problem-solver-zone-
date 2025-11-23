#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        for (int i = 0; i < n;i++)
        {
            int x;
            cin >> x;
            mp[x]++;
        }
        if(mp[k]!=0)
        {
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}