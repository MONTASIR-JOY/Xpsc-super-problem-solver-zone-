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
        int n;
        cin >> n;
        vector<int> v(n);
        int mex = 0;
        int mexidx = 0;
        bool x = true;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        vector<int> v1 = v;
        sort(v1.begin(), v1.end());
        vector<int> ans;
        for (int i = 0; i < n;i++)
        {
            if(v[i]==v1[i])
            {
                continue;
            }
            ans.push_back(v[i] & v1[i]);
        }
        int final = ans[0];
        for(int i:ans)
        {
            final &= i;
        }
        cout << final << endl;
    }
    return 0;
}