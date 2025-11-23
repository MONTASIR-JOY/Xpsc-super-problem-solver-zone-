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
        char ch;
        cin >> n >> ch;
        string s;
        cin>>s;

        set<int> ss;
        for (int i = 0; i < n;i++)
        {
            ss.insert(s[i]);
        }
        if(ss.size()==1 && s[0]==ch)
        {
            cout << 0 << endl;
            continue;
        }
        if(s[n-1]==ch)
        {
            cout << 1 << endl;
            cout << n << endl;
        }
        else if(s[n-2]==ch)
        {
            cout << 1 << endl;
            cout << n - 1 << endl;
        }
        else{
            cout << 2 << endl;
            cout << n - 1 << " " << n << endl;
        }
    }
    return 0;
}