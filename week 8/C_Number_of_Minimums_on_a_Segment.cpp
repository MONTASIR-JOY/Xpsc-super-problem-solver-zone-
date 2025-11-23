#include<bits/stdc++.h>
using namespace std;

const long long maxN = 1e5 + 9;
long long a[maxN];

struct node
{
    long long mn;
    long long cnt;
};
node t[4 * maxN + 9];
node merge(node l,node r)
{
    node ans;
    ans.mn = min(l.mn, r.mn);
    ans.cnt = 0;
    if(ans.mn==l.mn)
    {
        ans.cnt += l.cnt;
    }
    if(ans.mn==r.mn)
    {
        ans.cnt += r.cnt;
    }
    return ans;
}
void build(long long n,long long b,long long e)
{
    if(b==e)
    {
        t[n].mn = a[b];
        t[n].cnt = 1;
        return;
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = merge(t[l], t[r]);
}

void update(long long n,long long b,long long e,long long i,long long v)
{
    if(i<b || i>e)
    {
        return;
    }
    if(b==e)
    {
        t[n].mn = v;
        t[n].cnt = 1;
        return;
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    update(l, b, mid, i, v);
    update(r, mid + 1, e, i, v);
    t[n] = merge(t[l], t[r]);
}

node query(long long n,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return {LLONG_MAX, 0};
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    return merge(query(l, b, mid, i, j), query(r, mid + 1, e, i, j));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, m;
    cin >> n >> m;
    for (long long i = 1; i <= n;i++)
    {
        cin >> a[i];
    }
    build(1, 1, n);

    while(m--)
    {
        long long t;
        cin >> t;
        if(t==1)
        {
            long long idx, v;
            cin >> idx >> v;
            idx++;
            update(1, 1, n, idx, v);
        }
        else{
            long long l, r;
            cin >> l >> r;
            l++;
            node ans = query(1, 1, n, l, r);
            cout << ans.mn << " " << ans.cnt << endl;
        }
    }
    return 0;
}