#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long a[maxN], t[4 * maxN], lazy[4 * maxN];

void build(long long n,long long b,long long e)
{
    lazy[n] = -1;
    if(b==e)
    {
        t[n] = a[b];
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];    // change this
}

void push(long long n,long long b,long long e)
{
    if(lazy[n] == -1)
    {
        return;
    }
    t[n] = (e - b + 1) * lazy[n];
    if(b != e)
    {
        long long l = 2 * n;
        long long r = 2 * n + 1;
        lazy[l] = lazy[n];
        lazy[r] = lazy[n];
    }
    lazy[n] = -1;
}

void update(long long n,long long b,long long e,long long i,long long j,long long v)
{
    push(n, b, e);
    if(e<i || j<b)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        lazy[n] = v;
        push(n, b, e);
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    update(l, b, mid, i, j, v);
    update(r, mid + 1, e, i, j, v);
    t[n] = t[l] + t[r];   // change this
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    push(n, b, e);
    if(e<i || j<b)
    {
        return 0;         // return right value
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j); // change this
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n;i++)
    {
        a[i] = 0;
    }
    build(1, 1, n);

     while(m--)
    {
        long long type;
        cin >> type;
        if(type==1)
        {
            long long l, r, v;
            cin >> l >> r >> v;
            l++;
            update(1, 1, n, l, r, v);
        }
        else
        {
            long long l, r;
            cin >> l >> r;
            l++;
            cout << query(1, 1, n, l, r) << endl;
        }
    }
    return 0;
}



#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long a[maxN], t[4 * maxN], lazy[4 * maxN];

void build(long long n,long long b,long long e)
{
    lazy[n] = 0;
    if(b==e)
    {
        t[n] = a[b];
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = t[l] + t[r];    // change this
}

void push(long long n,long long b,long long e)
{
    if(lazy[n] == 0)
    {
        return;
    }
    t[n] += (e - b + 1) * lazy[n];
    if(b != e)
    {
        long long l = 2 * n;
        long long r = 2 * n + 1;
        lazy[l] += lazy[n];
        lazy[r] += lazy[n];
    }
    lazy[n] = 0;
}

void update(long long n,long long b,long long e,long long i,long long j,long long v)
{
    push(n, b, e);
    if(e<i || j<b)
    {
        return;
    }
    if(b>=i && e<=j)
    {
        lazy[n] += v;     // set correct propagation
        push(n, b, e);
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    update(l, b, mid, i, j, v);
    update(r, mid + 1, e, i, j, v);
    t[n] = t[l] + t[r];   // change this
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    push(n, b, e);
    if(e<i || j<b)
    {
        return 0;         // return right value
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */
    long long r = 2 * n + 1;            //    l   r
    return query(l, b, mid, i, j) + query(r, mid + 1, e, i, j); // change this
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n;i++)
    {
        a[i] = 0;
    }
    build(1, 1, n);

    
    return 0;
}