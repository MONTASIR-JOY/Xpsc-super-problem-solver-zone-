#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    vector<string >v;
    for (long long i = 0; i < n;i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }

    vector<string> pre;
    deque<string> suf;
    vector<bool> flag(n, false);
    string mid = "";
    bool x = false;
    for (long long i = 0; i < n; i++)
    {
        string a=v[i];
        bool matched = false;
        for (long long j = i + 1; j < n;j++)
        {
            string b = v[j];
            reverse(b.begin(), b.end());
            if (a == b &&flag[j] == false)
            {
                pre.push_back(v[i]);
                suf.push_front(v[j]);
                matched = true;
                flag[j] = true;
                break;
            }
        }
        if(!matched && !x)
        {
            string c = v[i];
            reverse(c.begin(), c.end());
            if(a==c)
            {
                mid = a;
                x = true;
            }
        }
    }
    string final;
    for (long long i = 0; i < pre.size();i++)
    {
        for(char ch:pre[i])
        {
            final.push_back(ch);
        }
    }
    if(x)
    {
        for(char ch:mid)
        {
            final.push_back(ch);
        }
    }
    for (long long i = 0; i < suf.size();i++)
    {
        for(char ch:suf[i])
        {
            final.push_back(ch);
        }
    }
    cout << final.size() << endl;
    cout << final << endl;
        return 0;
}