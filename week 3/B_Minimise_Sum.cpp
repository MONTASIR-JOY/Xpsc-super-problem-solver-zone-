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
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        if(n==2)
        {
            if(v[0]>v[1])
            {
                cout << v[0] + v[1] << endl;
                continue;
            }
            else{
                cout << 2 * v[0] << endl;
                continue;
            }
        }
        if(v[1]<=v[0])
        {
            v[0] = v[1]+v[0];
            v[1] = 0;
            //cout << v[0] << " "<<v[1]<<endl;
        }
        else{
            v[1] = v[1] + v[2];
            v[2] = 0;
            //cout << v[1] << " " << v[2] << " ";
            //cout << endl;
        }
        int ans = 0;
        int mn = INT_MAX;
        for (int i = 0; i < n;i++)
        {
            mn = min(mn, v[i]);
            ans += mn;
        }
        cout << ans << endl;
    }
    return 0;
}