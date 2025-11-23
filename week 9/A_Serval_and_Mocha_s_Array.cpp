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
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        bool ans = false;
        int gcd = 0;
        for (int i = 0; i < n;i++)
        {
            for (int j = i + 1; j < n;j++)
            {
                if(__gcd(v[i],v[j])<=2)
                {
                    ans = true;
                    break;
                }
            }
            if(ans)
            {
                break;
            }
        }
        if(ans)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}