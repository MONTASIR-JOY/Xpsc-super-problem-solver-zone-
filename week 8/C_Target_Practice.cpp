#include<bits/stdc++.h>
using namespace std;
int score[10][10] =
    {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 5, 5, 4, 3, 2, 1},
        {1, 2, 3, 4, 4, 4, 4, 3, 2, 1},
        {1, 2, 3, 3, 3, 3, 3, 3, 2, 1},
        {1, 2, 2, 2, 2, 2, 2, 2, 2, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
      
    int t;
    cin>>t;
    while(t--)
    {
        int n = 10;
        char a[n][n];
        int ans = 0;
        for (int i = 0; i < n;i++)
        {
            for (int j = 0; j < n;j++)
            {
                cin >> a[i][j];
                if(a[i][j]=='X')
                {
                    ans += score[i][j];
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}