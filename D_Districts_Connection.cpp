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
        set<int> s;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size()==1)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
            int dif = -1;
            for (int i = 0; i < n;i++)
            {
                if(v[0]!=v[i])
                {
                    cout << 1 << " " << i + 1 << endl;
                    dif = i + 1;
                }
            }
            for (int i = 1; i < n;i++)
            {
                if(v[i]==v[0])
                {
                    cout << dif << " " << i + 1 << endl;
                }
            }
        }
    }
    return 0;
}