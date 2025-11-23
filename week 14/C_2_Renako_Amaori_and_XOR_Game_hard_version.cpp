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
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
        }
        
        bool f = false;
        for (long long k = 31; k >= 0;k--)
        {
            long long aji = 0;
            long long mai = 0;
            for (long long i = 0; i < n; i++)
            {
                if (a[i]&(1LL <<k))
                {
                    aji++;
                }
                if (b[i]&(1LL<<k))
                {
                    mai++;
                }
            }

            if ((aji % 2)!=(mai%2))
            {
                for (long long i = n - 1; i >= 0; i--)
                {   
                    if ((a[i]&(1LL<<k))!=(b[i]&(1LL<<k)))
                    {
                        if (i % 2 == 0)
                        {
                            cout << "Ajisai" << endl;
                        } 
                        else
                        {
                            cout << "Mai" << endl;
                        }

                        f = true;
                        break;
                    }
                }
                if (f) break;
            }
        }
        
        if (!f){
            cout << "Tie" << endl;
        }
    }
    return 0;
}