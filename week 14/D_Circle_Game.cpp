#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long t;
    cin >> t;
    while(t--)
    {
        long long d, k;
        cin >> d >> k;
        long long x = 0;
        long long y = 0;
        long long trc = 1;
        while(1)
        {
            if(trc==1)
            {
                x += k;
            }
            else
            {
                y += k;
            }
            if(pow(x,2)+pow(y,2)>pow(d,2))
            {
                break;
            }
            trc ^= 1;
        }

        if(trc)
        {
            cout << "Utkarsh" << endl;
        }
        else{
            cout << "Ashish" << endl;
        }
    }
    return 0;
}