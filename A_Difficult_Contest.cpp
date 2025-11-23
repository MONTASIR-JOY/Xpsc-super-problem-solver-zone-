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
        string s;
        cin >> s;
        sort(s.rbegin(), s.rend());
        cout << s << endl;
    }
    return 0;
}