#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        n--;
        long long num = pow(2, __lg(n)) - 1;
        for (int i = num; i >= 0;i--)
        {
            cout << i << " ";
        }
        num = pow(2, __lg(n));
        for (int i = num; i <=n;i++)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}