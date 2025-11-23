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
        vector<long long> v(n);
        long long sum = 0;

        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
            sum += v[i];
        }

        sort(v.begin(), v.end());
        long long a = v[0];
        long long b = v[1];

        while(k)
        {
            long long append = (a + b + 1) / 2;
          
            if(append<b)
            {
                b = append;
                sum += append;
            }
            else{
                append *= k;
                sum += append;
                break;
            }
            k--;
        }
        cout << sum << endl;
    }
    return 0;
}