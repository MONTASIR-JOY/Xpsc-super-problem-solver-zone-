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
        int n;
        cin >> n;
        if(n<=2 || (n%2==1 || (n/2)%2==1))
        {
            cout << "Alice" << endl;
        }
        else{
            cout << "Bob" << endl;
        }
    }
    return 0;
}