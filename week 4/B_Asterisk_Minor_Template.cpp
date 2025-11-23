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
        string a, b;
        cin >> a >> b;
        if(a[0]==b[0])
        {
            cout << "YES" << endl;
            cout << a[0] << "*" << endl;
            continue;
        }
        if(a[a.size()-1]==b[b.size()-1])
        {
            cout << "YES" << endl;
            cout << "*" << a[a.size() - 1] << endl;
            continue;
        }
        int n = a.size();
        int m = b.size();
        string ans = "";
        for (int i = 1; i < n;i++)
        {
            bool y = false;
            for (int j = 1; j < m;j++)
            {
                if(a[i]==b[j] && a[i-1]==b[j-1])
                {
                    ans.push_back(a[i-1]);
                    ans.push_back(a[i]);
                    y = true;
                    break;
                }
            }
            if(y)
            {
                break;
            }
        }
        if(ans.size()<2)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            cout << "*" << ans << "*" << endl;
        }
    }
    return 0;
}