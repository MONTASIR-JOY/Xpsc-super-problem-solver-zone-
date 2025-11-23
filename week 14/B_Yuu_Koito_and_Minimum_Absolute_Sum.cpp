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
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            if(i!=0 && i!=n-1 && v[i]==-1)
            {
                v[i] = 0;
            }
        }

        if(v[0]==-1 && v[n-1]==-1)
        {
            cout << 0 << endl;
            v[0] = 0;
            v[n-1] = 0;
            for(int i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if(v[0]==-1)
        {
            cout << 0 << endl;
            v[0] = v[n-1];
            for(int i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else if(v[n-1]==-1)
        {
            cout << 0 << endl;
            v[n-1] = v[0];
            for(int i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
        else{
            cout << abs(v[n - 1] - v[0]) << endl;
            for(int i:v)
            {
                cout << i << " ";
            }
            cout << endl;
        }
    }
    return 0;
}