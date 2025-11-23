#include <bits/stdc++.h>
using namespace std;
int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    long long t;
    cin >> t;
    while (t--)
    {
        long long a, b, c, d;
        cin >> a >> b >> c >> d;
        long long k = min(min(a, b), min(c, d));
        if ((k == a || k == c) && (k != b && k != d)) 
        {
            cout << "Flower" << endl;
        } 
        else 
        {
            cout << "Gellyfish" << endl;
        }
    }
    return 0;
}
