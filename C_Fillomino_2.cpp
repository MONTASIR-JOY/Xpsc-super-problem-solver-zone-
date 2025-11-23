#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    vector<vector<long long>> mat(n, vector<long long>(n, 0));

    for(long long i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        long long row = i;
        long long col = i;
        long long val = x;
        while(x--)
        {
            mat[row][col] = val;
            if(col != 0 && mat[row][col-1] == 0)
            {
                col--;
            }
            else
            {
                row++;
            }
        }
    }
    for(long long i = 0; i < n; i++)
    {
        for(long long j = 0; j <= i; j++)
        {
            cout << mat[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}