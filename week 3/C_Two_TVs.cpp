#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    map<long long, long long> d;
    for (long long i = 0; i < n;i++)
    {
        long long l, r;
        cin >> l >> r;
        d[l]++;
        d[r+1]--;
    }
    long long sum = 0;
    for (auto val:d)
    {
        sum += val.second;
        if(sum>2)
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}