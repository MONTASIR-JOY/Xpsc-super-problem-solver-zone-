#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin>>t;
    while(t--)
    {
        int k,n;
        cin >> k>>n;
        vector<int> v(n);
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            v[i] = k - v[i];
        }
        sort(v.begin(), v.end());
        int sum = 0;
        int cnt = 0;
        int cat = 0;

        for(int i:v)
        {
            sum += i;
            
            if(k-cat<=i)
            {
                break;
            }
            cnt++;
            cat += i;
        }
        cout << cnt << endl;
    }
    return 0;
}