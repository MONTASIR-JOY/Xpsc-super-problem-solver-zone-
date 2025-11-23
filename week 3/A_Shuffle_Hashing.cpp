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
        string a, b;
        cin >> a;
        cin >> b;
        sort(a.begin(), a.end());
        bool ans = false;
        for (int i = 0; i + a.size() <= b.size(); i++)
        {
            string s = b.substr(i, a.size());
            sort(s.begin(), s.end());
            if(s==a)
            {
                ans = true;
                break;
            }
        }
        if (ans)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}