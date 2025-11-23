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
        int n, a, b;
        cin >> n >> a >> b;
        int mi = a + b;
        if(n==a && n==b)
        {
            cout << "Yes" << endl;
        }
        else if(n-mi>=2)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}