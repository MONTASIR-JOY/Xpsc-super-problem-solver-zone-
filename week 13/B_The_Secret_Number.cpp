#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        vector<long long> ans;
        long long trc = 1;
        long long div = trc*10 + 1;
        while(div<=n)
        {
            if(n%div==0)
            {
                ans.push_back(n / div);
            }
            trc*=10;
            div = trc*10 + 1;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size() << endl;
        for(long long i:ans)
        {
            cout << i << " ";
        }
        if(ans.size()!=0)
            cout << endl;
    }
    
    return 0;
}