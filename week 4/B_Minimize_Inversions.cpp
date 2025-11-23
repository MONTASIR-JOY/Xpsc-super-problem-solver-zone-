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
        int n;
        cin >> n;
        vector<int> a(n);
        vector<int> b(n);
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        map<int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> b[i];
            mp[a[i]] = b[i];
        }
        sort(a.begin(),a.end());
        for (int i = 0; i < n;i++)
        {
            cout << a[i] << " ";
        }
        cout << endl;

        for (int i = 0; i < n;i++)
        {
            cout << mp[a[i]] << " ";
        }
        cout << endl;
    }
    return 0;
}