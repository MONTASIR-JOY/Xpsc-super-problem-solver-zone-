#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin >> n >> k;
        int s = n - k + 1;
        for (int i = s; i >= 1;i--)
        {
            cout << i << " ";
        }
        for (int i = s + 1; i <= n;i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}