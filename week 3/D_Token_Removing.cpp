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
        long long n, m;
        cin >> n >> m;
        long long sum = 1;
        for (long long i = 1; i <= n + 1;i++)
        {
            sum = ((sum % m) * (i % m)) % m;
        }
        cout << sum << endl;
    }
    return 0;
}