#include<bits/stdc++.h>
using namespace std;

long long f(long long n,long long l,long long r)
{
    return r / n - (l - 1) / n;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while(t--)
    {
        long long l, r;
        cin>>l>>r;

        long long cnt = 0;
        cnt += f(2, l, r);
        cnt += f(3, l, r);
        cnt += f(5, l, r);
        cnt += f(7, l, r);

        cnt -= f(6, l, r);
        cnt -= f(10, l, r);
        cnt -= f(14, l, r);
        cnt -= f(15, l, r);
        cnt -= f(21, l, r);
        cnt -= f(35, l, r);

        cnt += f(30, l, r);
        cnt += f(42, l, r);
        cnt += f(70, l, r);
        cnt += f(105, l, r);

        cnt -= f(210, l, r);

        cout << r - l + 1 - cnt << endl;
    }
    return 0;
}