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
        if(n==1)
        {
            cout << -1 << endl;
            continue;
        }

        vector<long long> ve = v;
        sort(ve.begin(), ve.end());
        for (long long i = 0; i < n-1;i++)
        {
            if(v[i]==ve[i])
            {
                swap(ve[i], ve[i + 1]);
            }
        }
        if(v[n-1]==ve[n-1])
        {
            swap(ve[n - 1], ve[n - 2]);
        }

        for(long long i:ve)
        {
            cout << i << " ";
        } 
        cout << endl;
    }
    return 0;
}