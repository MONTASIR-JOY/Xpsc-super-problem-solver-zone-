#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    bool x = false;
    for (int i = 2; i * i <= n;i++)
    {
        if(n%i==0)
        {
            x = true;
            break;
        }
    }
    
    int two = n / 2;
    if(n%2==1)
    {
        two--;
        cout << two +1 << endl;
    }
    else{
        cout << two << endl;
    }
    for (int i = 0; i < two;i++)
    {
        cout << 2 << " ";
    }
    if(n%2!=0)
    {
        cout << 3 << endl;
    }
    
    return 0;
}