#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    long long n;
    cin >> n;

    vector<bool> prime(n + 1, true);
    for (long long i = 2; i * i <= n+1;i++)
    {
        if(prime[i])
        {
            for (long long j = i + i; j <= n+1; j += i)
            {
                prime[j] = false;
            }
        }
    }
    if(n==1)
    {
        cout << 1 << endl;
        cout << 1 << endl;
        return 0;
    }
    if(n==2)
    {
        cout << 1 << endl;
        cout << 1 << " " << 1 << endl;
        return 0;
    }
    cout << 2 << endl;
    for (long long i = 2; i <= n+1;i++)
    {
        if(prime[i])
        {
            cout << 1 << " ";
        }
        else{
            cout << 2 << " ";
        }
    }
        return 0;
}