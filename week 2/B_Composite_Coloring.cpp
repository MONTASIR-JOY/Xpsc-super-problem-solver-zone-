#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin >> t;
    vector<int> prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
        }
        map<int, vector<int>> mp;

        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < 11; j++) 
            {
                if (v[i] % prime[j] == 0) 
                {
                    mp[prime[j]].push_back(i);
                    break;
                }
            }
        }

        vector<int> ans(n);
        int color = 1;
        for (auto val : mp) 
        {
            for (auto pos : val.second) 
            {
                ans[pos] = color;
            }
            color++;
        }

        cout << mp.size() << endl;
        for (int i = 0; i < n; i++) 
        {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}