#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    map<int, int> cnt;

    for (int i = 2; i * i <= n;i++)
    {
        while(n%i==0)
        {
            cnt[i]++;
            n /= i;
        }
    }
    
    if(n>1)
    {
        cnt[n]++;
    }
    for(auto val:cnt)
    {
        cout << val.first << " " << val.second << endl;
    }
    return 0;
}