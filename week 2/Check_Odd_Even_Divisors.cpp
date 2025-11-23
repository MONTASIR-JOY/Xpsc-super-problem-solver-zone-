#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin >> t;
    while(t--)
    {
        long long a, b;
        cin >> a >> b;
        if(a>0 && b%a==0)
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