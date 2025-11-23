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
        long long n, k;
        cin >> n >> k;

        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        b = a;

        if (k <= 2)
        {
            cout << "YES" << endl;
            continue;
        }

        sort(b.begin(), b.end());

        long long x = b[k - 2];

        deque<long long> dq;

        for (long long i = 0; i < n;i++)
        {
            if(a[i] <= x)
            {
                dq.push_back(a[i]);
            }
        }

        long long cnt = dq.size() - (k - 1);
        bool ok = true;
        while(dq.size()>1)
        {
            if(dq.front() == dq.back())
            {
                dq.pop_back();
                dq.pop_front();
            }
            else if(cnt && dq.front() == x)
            {
                dq.pop_front();
                cnt--;
            }
            else if(cnt && dq.back() == x)
            {
                dq.pop_back();
                cnt--;
            }
            else
            {
                ok = false;
                break;
            }
        }
        if(ok)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}