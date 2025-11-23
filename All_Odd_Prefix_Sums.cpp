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
        int odd = 0;
        int even = 0;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            if(v[i]%2==1)
            {
                odd++;
            }
            else{
                even++;
            }
        }
        if(odd==1)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}