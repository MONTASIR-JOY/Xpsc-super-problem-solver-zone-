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
        vector<long long> v(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> v[i];
        }
        // for(long long i:v)
        // {
        //     cout << i << " ";
        // }
        // cout << endl;
        bool two = false;

        for (long long i = 0; i < n;i++)
        {
            if(v[i]%2!=0)
            {
                two = true;
                break;
            }
        }
        if(two)
        {
            cout << 2 << endl;
            continue;
        }


        bool three = false;

        for (long long i = 0; i < n;i++)
        {
            if(v[i]%3!=0)
            {
                three = true;
                break;
            }
        }
        if(three)
        {
            cout << 3 << endl;
            continue;
        }




        bool five = false;

        for (long long i = 0; i < n;i++)
        {
            if(v[i]%5!=0)
            {
                five = true;
                break;
            }
        }
        if(five)
        {
            cout << 5 << endl;
            continue;
        }
    }
    return 0;
}