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
        int a = -1;
        int b = -1;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]==1)
            {
                a = i + 1;
            }
            if(v[i]==n)
            {
                b = i + 1;
            }
        }
        string x;
        cin >> x;

        if(x[0]=='1' || x[a-1]=='1' || x[b-1]=='1' || x[n-1]=='1')
        {
            cout << -1 << endl;
            continue;
        }

        cout << 5 << endl;
        cout << 1 << " " << n << endl;
        cout << 1 << " " << min(a, b) << endl;
        cout << 1 << " " << max(a, b) << endl;
        cout << min(a, b) << " " << n << endl;
        cout << max(a, b) << " " << n << endl;
    }
    return 0;
}