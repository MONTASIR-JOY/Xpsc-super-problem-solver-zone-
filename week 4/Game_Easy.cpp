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
        int s = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            s += v[i];
        }
        int last = 0;
        sort(v.rbegin(), v.rend());
        for (int i = 1; i <= 2 * n;i++)
        {
            int ans = 0;
            int cost = i;
            int x = 0;
            if(cost<=n)
            {
                for (int j = 0; j < n;j++)
                {
                    if(cost==0)
                    {
                        break;
                    }
                    if(j<n-1 && x>v[j+1] && cost==2)
                    {
                        ans += (v[j] + x);
                        x++;
                        cost -= 2;
                        last = j;
                    }
                    else{
                        x++;
                        ans += v[j];
                        cost -= 1;
                        last = j;
                    }
                }
                cout << ans <<" ";
            }
            else{
                cout << last << endl;
                cout << s + x << endl;
            }
        }
        cout << endl;
    }
    return 0;
}