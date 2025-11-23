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
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        set<char> se;
        for(char i:s)
        {
            se.insert(i);
        }
        if(se.size()==1)
        {
            cout << "NO" << endl;
            continue;
        }
        string s1=s;
        reverse(s1.begin(), s1.end());
        if(s1<=s && k==0)
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}