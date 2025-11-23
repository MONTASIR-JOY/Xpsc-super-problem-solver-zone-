#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long t;
    cin>>t;
    while(t--)
    {
        long long a, b, l;
        cin >> a >> b >> l;
        set<long long> s;
        for (long long i = 0; i < 21;i++)
        {
            long long fir = 1;
            for (int k = 0; k < i;k++)
            {
                fir *= a;
            }
            if(fir>l)
            {
                break;
            }
            if (l % fir == 0)
            {
                long long val = l / fir;
                for (long long j = 0; j < 21; j++)
                {
                    long long se = 1;
                    for (int k = 0; k < j;k++)
                    {
                        se *= b;
                    }
                    if(se>val)
                    {
                        break;
                    }
                    if (val % se == 0)
                    {
                        s.insert(val / se);
                    }
                }
            }
        }
        cout << s.size() << endl;
    }
    return 0;
}