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
        sort(v.begin(), v.end());
        int mex = 0;
        for (int i = 0; i < n;i++)
        {
            if(v[i]==mex)
            {
                mex++;
            }
        }
        cout << mex << endl;
    }
    return 0;
}