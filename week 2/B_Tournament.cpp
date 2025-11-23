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
        int n, j, k;
        cin >> n >> j >> k;
        vector<int>v(n);
        int val = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            if(i+1==j)
            {
                val = v[i];
            }
        }
        sort(v.begin(), v.end());
        if(k==1 && val!=v[n-1])
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }         
    }
    return 0;
}