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

        bool x = false;
        while(!x)
        {
            long long dupn = n;
            vector<long long> v;
            while(dupn)
            {
                v.push_back(dupn % 10);
                dupn /= 10;
            }

            bool y = true;
            for (long long i = 0; i < v.size();i++)
            {
                if(v[i]!=0 && n%v[i]!=0)
                {
                    y = false;
                }
            }
            if(y)
            {
                x = true;
            }
            else{
                n++;
            }
        }
        cout << n << endl;
    }
    return 0;
}