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
        int mx = INT_MIN;
        for (int x = 1; x < 101;x++)
        {
            int sum = 0;
            for (int i = 0; i < n;i++)
            {
                sum += (min(v[i],x) * 50 - x * 30);
            }
            mx = max(mx, sum);
        }
        cout << mx << endl;
    }
    return 0;
}