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
        long long n;
        cin >> n;
        vector<long long> a(n);
        vector<long long> b(n);
        for (long long i = 0; i < n;i++)
        {
            cin >> a[i];
        }
        long long l = 0;
        bool bl = false;
        for (long long i = 0; i < n;i++)
        {
            cin >> b[i];
            if(a[i]!=b[i] && !bl)
            {
                l = i;
                bl = !bl;
            }
        }
        while(l>0)
        {
            if (b[l] < b[l-1])
            {
                break;
            }
            l--;
        }
        l++;
        long long r = n - 1;
        bl = false;
        for (long long i = n - 1;i>=0;i--)
        {
            if(a[i]!=b[i])
            {
                r = i;
                break;
            }
        }
        while(r<n-1)
        {
            if (b[r] > b[r+1])
            {
                break;
            }
            r++;
        }
        r++;
        cout << l << " " << r << endl;
    }
    return 0;
}