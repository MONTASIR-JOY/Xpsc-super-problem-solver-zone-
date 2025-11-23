#include<bits/stdc++.h>
using namespace std;

const long long mxn = 4e4 + 9;
const long long n = 502;
const long long m = 4e4+7;
const long long mod = 1e9 + 7;
vector<long long> palindrome;
long long dp[n][m];

long long f(long long i,long long sum)
{
    if(i>=palindrome.size())
    {
        return sum == 0;
    }

    if(dp[i][sum]!=-1)
    {
        return dp[i][sum];
    }
    long long ans = 0;
    if(palindrome[i]<=sum)
    {
        ans += f(i, sum - palindrome[i]);
    }
    ans += f(i + 1, sum);
    return dp[i][sum] = ans%mod;
}
void pal()
{
    for (long long i = 1; i <= mxn;i++)
    {
        string s = to_string(i);
        string s1 = s;
        reverse(s1.begin(), s1.end());
        if(s1==s)
        {
            palindrome.push_back(i);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    pal();
    memset(dp, -1, sizeof(dp));

    long long t;
    cin >> t;
    while(t--)
    {
        long long n;
        cin >> n;
        
        cout << f(0, n) << endl;
    }
    return 0;
}