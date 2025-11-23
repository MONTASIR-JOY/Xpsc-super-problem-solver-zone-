#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> v(n);
    int cnt = 0;
    for (int i = 0; i < n;i++)
    {
        cin >> v[i].first >> v[i].second;
        if(v[i].first>0)
        {
            cnt++;
        }
    }
    if(cnt==n || cnt==n-1 ||cnt==1 ||cnt==0)
    {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
        return 0;
}