#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, x;
    cin >> a >> b >> c >> x;

    if(a*b*c==x*x*x)
    {
        cout << "Equal" << endl;
        
    }
    else if(a*b*c>x*x*x)
    {
        cout << "Cuboid" << endl;
        
    }
    else if(a*b*c<x*x*x)
    {
        cout << "Cube" << endl;
        
    }
    return 0;
}