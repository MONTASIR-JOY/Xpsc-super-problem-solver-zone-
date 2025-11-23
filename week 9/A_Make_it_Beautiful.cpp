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
        set<int> s;
        for (int i = 0; i < n;i++)
        {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size()==1)
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
        sort(v.rbegin(),v.rend());
        int first = v[0];
        if(first==v[1])
        {
            int idx = 0;
            for (int i = 0; i < n;i++)
            {
                if(v[i]!=first)
                {
                    idx = i;
                    break;
                }
            }
            swap(v[1], v[idx]);
        }
        for(int i:v)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}