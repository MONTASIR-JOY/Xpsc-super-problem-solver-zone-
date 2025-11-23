// eibar mile ja vai
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
        long long n, x;
        cin >> n >> x;
        string s;
        cin >> s;
        if(x==1 || x==n)
        {
            cout << 1 << endl;
            continue;
        }
        x--;
        long long f = -1;
        for (long long i = 0; i < x;i++)
        {
            if(s[i]=='#')
            {
                f = i;
            }
        }
        long long l = -1;
        for (long long i = n - 1; i >= x + 1;i--)
        {
            if(s[i]=='#')
            {
                l = i;
            }
        }
        if(f==-1 && l==-1)
        {
            cout << 1 << endl;
            continue;
        }
        if(f==-1)
        {
            f = x;
            cout << min(f, n - l) + 1 << endl;
            continue;
        }
        if (l==-1)
        {
            l = x+1;
            f++;
            //cout << f << " " << l << endl;
            cout << min(f, n - l) + 1 << endl;
            continue;
        }
        f++;
        l = n - l;
        //cout << f << " " << l << endl;
        cout << min({max(f, l), x, n - x - 1}) + 1 << endl;
    }
    return 0;
}




