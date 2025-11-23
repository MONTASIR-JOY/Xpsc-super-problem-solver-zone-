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
        string s;
        cin >> s;
        char ch1 = s[0];
        char ch2 = s[1];
        vector<string> ans;
        for (char i = '1'; i <= '8';i++)
        {
            string p;
            p.push_back(ch1);
            p.push_back(i);
            if(p==s)
            {
                continue;
            }
            ans.push_back(p);
        }
        for (char i = 'a'; i <= 'h';i++)
        {
            string p;
            p.push_back(i);
            p.push_back(ch2);
            if(p==s)
            {
                continue;
            }
            ans.push_back(p);
        }

        for(string i:ans)
        {
            cout << i << endl;
        }
    }
    return 0;
}