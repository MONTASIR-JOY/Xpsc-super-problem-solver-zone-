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

        int id = 1;
        int mx = INT_MIN;
        for (int i = 0; i < n;i++)
        {
            if(mx<v[i])
            {
                id = i + 1;
                mx = v[i];
            }
        }
        cout << id << endl;
    }

    return 0;
}