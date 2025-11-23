#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n;
    cin >> n;
    vector<long long> v(n);

    for (long long i = 0; i < n; i++) 
    {
        cin >> v[i];
    }

    if (n == 1) 
    {
        cout << v[0] << endl;
        return 0;
    }

    vector<long long> freq(n + 2, 0);
    long long mx1 = 0;
    long long mx2 = 0;

    for (long long i = 0; i < n; i++) 
    {
        if (v[i] > mx1) 
        {
            mx2 = mx1;
            mx1 = v[i];
            freq[mx1] = -1;
        } 
        else if (v[i] > mx2) 
        {
            freq[mx1]++;
            mx2 = v[i];
        }
    }

    long long mx = freq[1];
    long long ans = 1;

    for (long long i = 2; i <= n; i++)
    {
        if (freq[i] > mx)
        {
            mx = freq[i];
            ans = i;
        }
    }

    cout << ans << endl;
    return 0;
}