#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin >> t;
    int sz = 1e7+5;
    vector<bool> prime(sz, true);
    prime[0] = false;
    for (int i = 2; i * i <= sz;i++)
    {
        if(prime[i])
        {
            for (int j = i + i; j <= sz;j+=i)
            {
                prime[j] = false;
            }
        }
    }
    while(t--)
    {
        int n;
        cin >> n;
        int cnt = 0;
        for (int i = 2; i <= n;i++)
        {
            if(prime[i])
            {
                cnt += n / i;
            }
        }
        cout << cnt << endl;

    }
    return 0;
}