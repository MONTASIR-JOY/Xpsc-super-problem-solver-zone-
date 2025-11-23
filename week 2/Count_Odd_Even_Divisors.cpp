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
        set<int> s;
        for (int i = 1; i * i <= n;i++)
        {
            if(n%i==0)
            {
                s.insert(i);
                s.insert(n/i);
            }
        }
        int odd = 0;
        int even = 0;
        for(int i:s)
        {
            if(i%2==0)
            {
                even++;
            }
            else{
                odd++;
            }
        }
        cout << odd << " " << even << endl;
    }
    return 0;
}