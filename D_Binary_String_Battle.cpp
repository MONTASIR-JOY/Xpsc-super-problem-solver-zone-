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
        string s;
        cin >> s;
        int z = 0;
        int o = 0;
        for (int i = 0; i < n;i++)
        {
            if(s[i]=='0')
            {
                z++;
            }
        }
        o = n - z;
        if(2*k>n || o<=k)
        {
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}