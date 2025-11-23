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
        string ans="";
        int l=0;
        int r = n - 1;
        int flag = 0;
        while(l<=r)
        {
            if(l==r)
            {
                ans += "L";
            }
            else if(flag==0)
            {
                if(v[r]>v[l])
                {
                    ans += "LR";
                }
                else
                {
                    ans += "RL";
                }
            }
            else
            {
                if(v[r]>v[l])
                {
                    ans += "RL";
                }
                else{
                    ans += "LR";
                }
            }
            flag ^= 1;
            l++;
            r--;
        }
        cout << ans << endl;
    }
    return 0;
}