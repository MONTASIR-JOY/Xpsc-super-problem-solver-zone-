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
        int n;
        cin >> n;
        vector<int> v(n);
        
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        int ans = v[0];
        for (int i = 1; i < n;i++)
        {
            ans ^= v[i];
        }
        if(n%2==0)
        {
            if(ans==0)
            {
                cout << 0 << endl;
            }
            else{
                cout << -1 << endl;
            }
        }
        else{
            cout << ans << endl;
        }
    }
    return 0;
}