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
        int n, l, r;
        cin >> n >> l >> r;
        vector<int> v(n);
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if(v[i]>=l && v[i]<=r)
            {
                cnt++;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}