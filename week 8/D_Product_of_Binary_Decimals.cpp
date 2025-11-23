#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;

        vector<long long> v;
        v.push_back(10);
        v.push_back(11);

        long long i = 0;
        while (true)
        {
            if (i >= v.size())
                break;
            long long x = v[i] * 10;
            long long y = x + 1;
            if (x <= n)
            {
                v.push_back(x);
            }
            if (y <= n)
            {
                v.push_back(y);
            }
            i++;
        }
       
        sort(v.begin(),v.end(), greater<long long>());
        while (n > 1)
        {
            long long find = 0;
            for (long long i = 0; i < v.size(); i++)
            {
                if (n % v[i] == 0)
                {
                    n /= v[i];
                    find = 1;
                }
            }
            if (find==0)
            {
                break;
            }
        }
        if (n == 1)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}