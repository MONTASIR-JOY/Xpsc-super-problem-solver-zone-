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
        vector<int> v(n-1);
        int sum = 0;
        for (int i = 0; i < n-1;i++)
        {
            cin >> v[i];
            sum += v[i];
        }
        cout << -sum << endl;
    }
    return 0;
}