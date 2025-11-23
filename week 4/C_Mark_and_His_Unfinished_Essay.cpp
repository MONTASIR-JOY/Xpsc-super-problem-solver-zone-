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
        long long n, c, q;
        cin >> n >> c >> q;
        string s;
        cin >> s;
        vector<long long> right(c + 1);
        vector<long long> left(c + 1);
        vector<long long> dif(c + 1);
        right[0]=n;
        left[0] = 0;
        dif[0] = n;
        for (long long i = 1; i <= c;i++)
        {
            long long l, r;
            cin >> l >> r;
            l--;
            r--;
            left[i] = right[i - 1];
            right[i] = left[i] + (r - l + 1);
            dif[i] = left[i] - l;
        }
        while(q--)
        {
            long long k;
            cin >> k;
            k--;
            for (long long i = c; i >= 1;i--)
            {
                if(k<left[i])
                {
                    continue;
                }
                else
                {
                    k -= dif[i];
                }
            }
            cout << s[k] << endl;
        }
    }
    return 0;
}