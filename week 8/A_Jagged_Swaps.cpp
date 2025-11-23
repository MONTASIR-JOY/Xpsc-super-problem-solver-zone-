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
        if(v[0]!=1)
        {
            cout << "NO" << endl;
        }
        else{
            cout << "YES" << endl;
        }
    }
    return 0;
}