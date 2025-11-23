#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
    }
    bool ans = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            if (s[i][j] == '.' &&
                i + 2 < n &&
                s[i + 1][j - 1] == '.' &&
                s[i + 1][j] == '.' &&
                s[i + 1][j + 1] == '.' &&
                s[i + 2][j] == '.')
            {
                s[i][j] = '#';
                s[i + 1][j - 1] = '#';
                s[i + 1][j] = '#';
                s[i + 1][j + 1] = '#';
                s[i + 2][j] = '#';
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '.')
            {
                ans = false;
                break;
            }
        }
    }
    if (ans)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    return 0;
}