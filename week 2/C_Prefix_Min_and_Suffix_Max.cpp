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

        vector<bool> pre(n, false);
        vector<int> suf(n, false);
       
        int mn = v[0];
        // cout << mn << endl;
        for (int i = 1; i < n;i++)
        {
            if(mn<v[i])
            {
                pre[i] = true;
            }
            else{
                mn = v[i];
            }
        }
        int mx = v[n-1];
        for (int i = n-2; i >= 0;i--)
        {
            if(mx>v[i])
            {
                suf[i] = true;
            }
            else{
                mx = v[i];
            }
        }

        for (int i = 0; i < n;i++)
        {
            if(pre[i] && suf[i])
            {
                cout << 0;
            }
            else{
                cout << 1;
            }
        }
        cout << endl;
    }
    return 0;
}
