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
        int n, x;
        cin >> n >> x;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<int> ans;
        for (int i = 0; i < n - 1;i++)
        {
            ans.push_back(v[i + 1] - v[i]);
        }
        ans.push_back(2 * (x - v[n - 1]));
        ans.push_back(v[0]);
        sort(ans.rbegin(), ans.rend());
        cout << ans[0] << endl;
    }
    return 0;
}