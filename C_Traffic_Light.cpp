#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        char ch;
        cin >> ch;
        string s;
        cin >> s;
        s += s;

        n = 2 * n;
        vector<long long> v;
        long long r = 0;
        for (long long i = n - 1; i >= 0;i--)
        {
            if(s[i]=='g')
            {
                r = i;
            }
            if(s[i]==ch  && r!=0)
            {
                v.push_back(abs(i - r));
            }
        }
        sort(v.begin(), v.end());
        cout << v[v.size() - 1] << endl;
    }
    return 0;
}