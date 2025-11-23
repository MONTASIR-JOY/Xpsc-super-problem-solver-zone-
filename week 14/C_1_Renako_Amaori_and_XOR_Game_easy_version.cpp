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
        vector<int> a(n);
        vector<int> b(n);
        int aji = 0;
        int mai = 0;
        for (int i = 0; i < n;i++)
        {
            cin >> a[i];
            aji ^= a[i];
        }
        for (int i = 0; i < n;i++)
        {
            cin >> b[i];
            mai ^= b[i];
        }
        bool found = false;
        int ans = -1;
        for (int i = n - 1; i >= 0;i--)
        {
            if(a[i]^b[i])
            {
                ans = i;
                break;
            }
        }

        if(ans!=-1)
        {
            aji ^= a[ans];
            mai ^= b[ans];
            if(ans%2==0 && aji==mai)
            {
                cout << "Ajisai" << endl;
            }
            else if(ans%2==1 && aji==mai)
            {
                cout << "Mai" << endl;
            }
            else
            {
                cout << "Tie" << endl;
            }
            continue;
        }

        if(aji>mai)
        {
            cout<<"Ajisai"<<endl;
        }
        else if(aji<mai)
        {
            cout << "Mai" << endl;
        }
        else{
            cout << "Tie" << endl;
        }
    }
    return 0;
}