#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << 2 << endl;
    for (int i = 1; i <= n;i++)
    {
        cout << i << " ";
    }
    cout << endl;
    for (int i = n; i >= 1;i--)
    {
        cout << i << " ";
    }
        return 0;
}