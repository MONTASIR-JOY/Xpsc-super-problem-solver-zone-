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
        n = n * 2;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        // for(int i:v)
        // {
        //     cout << i << " ";
        // }
        cout << v[n/2] - v[n/2 - 1] << endl;
    }
    return 0;
}