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
        string s;
        cin >> s;
        int i = 0;
        while(s[i]!=s[n-i-1] && i<=n-i-1)
        {
            i++;
        }
        cout << n-2*i << endl;
    }
    return 0;
}