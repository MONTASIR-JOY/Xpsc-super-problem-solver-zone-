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
        vector<int>v(n);
        for (int i = 0;i<n;i++)
        {
            cin >> v[i];
        }

        if(n<=2)
        {
            cout << "YES" << endl;
            continue;
        }
        int l = 0;
        int r = n - 1;
        bool ans = true;
        int val = 0;
        int val2 = 0;
        bool first = false;
        while(l<r)
        {
            if(v[l]==val && val!=0)
            {
                l++;
                continue;
            }
            if(v[r]==val && val!=0)
            {
                r--;
                continue;
            }
            if (v[l] != v[r] && first == false)
            {
                val = v[l];
                val2 = v[r];
                first = true;
                continue;
            }
            if(v[l]!=v[r])
            {
                ans = false;
                break;
            }
            l++;
            r--;
        }
        if(ans)
        {
            cout << "YES" << endl;
            continue;
        }
        l = 0;
        r = n - 1;
        ans = true;
        while(l<r)
        {
            if(v[l]==val2 && val2!=0)
            {
                l++;
                continue;
            }
            if(v[r]==val2 && val2!=0)
            {
                r--;
                continue;
            }
            if (v[l] != v[r] && first == false)
            {
                val = v[l];
                val2 = v[r];
                first = true;
                continue;
            }
            if(v[l]!=v[r])
            {
                ans = false;
                break;
            }
            l++;
            r--;
        }
        if(ans)
        {
            cout << "YES" << endl;
            continue;
        }
        cout << "NO" << endl;
    }
    return 0;
}