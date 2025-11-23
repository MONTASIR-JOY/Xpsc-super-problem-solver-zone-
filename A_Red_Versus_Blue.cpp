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
        long long n, r, b;
        cin >> n >> r >> b;
        string s;

        long long l = r / (b + 1);
        long long extra = r % (b + 1);

        for (long long i = 0; i < b + 1; i++)
        {
            for (long long i = 0; i < l; i++)
            {
                cout << 'R';
            }
            if (extra > 0)
            {
               cout << 'R';
                extra--;
            }
            if (i != b)
            {
                cout << 'B';
            }
        }
        cout << endl;
    }
    return 0;
}