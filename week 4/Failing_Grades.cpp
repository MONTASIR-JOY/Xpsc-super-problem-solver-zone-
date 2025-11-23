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
        bool x = true;
        int sum = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            sum += v[i];
            if(sum/(i+1)<40)
            {
                x = false;
            }
        }
        if(x)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}