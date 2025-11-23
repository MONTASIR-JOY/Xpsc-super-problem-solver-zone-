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
        long long n, x;
        cin >> n >> x;
        long long ans = 0;
        for (long long k = 0; k < 3;k++)
        {
            vector<long long> v(n);
            for (long long i = 0; i < n;i++)
            {
                cin >> v[i];
            }
            for (long long i = 0; i < n;i++)
            {
                if((v[i]&x)==v[i])
                {
                    ans |= v[i];
                }
                else
                {
                    break;
                }
            }
        }
        if(ans==x)
        {
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}