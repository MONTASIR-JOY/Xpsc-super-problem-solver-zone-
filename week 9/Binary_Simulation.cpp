#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long a[maxN], t[4 * maxN], lazy[4 * maxN];

void build(long long n,long long b,long long e)
{
    lazy[n] = 0;     // change this
    if(b==e)
    {
        t[n] = 0;
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = 0; // change this
}

void push(long long n,long long b,long long e)
{
    if(lazy[n] == 0)   // change this
    {
        return;
    }
    t[n] ^= lazy[n];
    if(b != e)
    {
        long long l = 2 * n;
        long long r = 2 * n + 1;
        lazy[l] ^= lazy[n];
        lazy[r] ^= lazy[n];
    }
    lazy[n] = 0;       // change this
}

void update(long long n,long long b,long long e,long long i,long long j)
{
    push(n, b, e);
    if(e<i || j<b)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        lazy[n] ^=1; // set correct propagation
        push(n, b, e);
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    update(l, b, mid, i, j);
    update(r, mid + 1, e, i, j);
    t[n] = t[l] ^ t[r];
}

long long query(long long n,long long b,long long e,long long i)
{
    push(n, b, e);
    if(b==e)
    {
        return a[b] ^ t[n];
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    if(i<=mid)
    {
        return query(l, b, mid, i);
    }
    else{
        return query(r, mid + 1, e, i);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    long long test;
    cin >> test;
    long long y = 0;
    while(test--)
    {
        y++;
        cout << "Case " << y << ":" << endl;
        string s;
        cin >> s;
        s = " " + s;
        long long n = s.size()-1;
        for (long long i = 1; i <= n;i++)
        {
            if(s[i]=='0')
            {
                a[i] = 0;
            }
            else
            {
                a[i] = 1;
            }
        }
        
        build(1, 1, n);
        long long m;
        cin >> m;
        while(m--)
        {
            char ch;
            cin >> ch;
            if(ch=='I')
            {
                long long l, r;
                cin >> l >> r;
                update(1, 1, n, l, r);
            }
            else
            {
                long long l;
                cin >> l;
                cout << query(1, 1, n, l) << endl;
            }
        }
    }
    return 0;
}

