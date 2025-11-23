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
        vector<int> v(n);
        int z = 0;
        int sum = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            sum += v[i];
            if(v[i]==0)
            {
                z++;
                sum++;
            }
        }
        cout << z + (sum == 0) << endl;
    }
    return 0;
}