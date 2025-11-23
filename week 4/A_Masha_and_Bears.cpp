#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if(a<=b || b<=c || b<=d)
    {
        cout << -1 << endl;
        return 0;
    }
    if(2*c<d)
    {
        cout << -1 << endl;
        return 0;
    }
    if(2*d<c)
    {
        cout << -1 << endl;
        return 0;
    }
    
    a = 2 * a - 1;
    b = 2 * b - 1;
    c = max(c, d);

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    return 0;
}