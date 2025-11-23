#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int qa, qb;
    cin >> qa >> qb;
    int ka, kb;
    cin >> ka >> kb;
    int goa, gob;
    cin >> goa >> gob;
    bool ans = true;
    if(qa==goa || qb==gob)
    {
        cout << "NO" << endl;
        return 0;
    }

    if(qa>ka)
    {
        if(qa<goa)
        {
            ans = false;
        }
    }
    if(qa<ka)
    {
        if(qa>goa)
        {
            ans = false;
        }
    }
    if(qb<kb)
    {
        if(qb>gob)
        {
            ans = false;
        }
    }
    if(qb>kb)
    {
        if(qb<gob)
        {
            ans = false;
        }
    }
    if(ans)
    {
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
}