#include <bits/stdc++.h>
using namespace std;

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string a, b;
    cin >> a >> b;

    long long n = a.size();
    long long m = b.size();

    vector<long long> v(n);
    for (long long i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    auto ok = [&](long long mid) 
    {
        vector<bool> removed(n, false);
        for (long long i = 0; i < mid; i++) 
        {
            removed[v[i] - 1] = true; 
        }
        long long j = 0;
        for (long long i = 0; i < n; i++) 
        {
            if (!removed[i] && a[i] == b[j]) 
            {
                j++;
                if (j == m) return true;
            }
        }
        return false;
    };

    long long l = 0, r = n, ans = 0;
    while (l <= r) 
    {
        long long mid = l + (r - l) / 2;
        if (ok(mid)) 
        {
            ans = mid;
            l = mid + 1;
        } 
        else 
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
    return 0;
}