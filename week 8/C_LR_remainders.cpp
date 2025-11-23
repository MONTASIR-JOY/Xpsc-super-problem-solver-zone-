#include<bits/stdc++.h>
using namespace std;

const long long maxN = 2e5 + 9;
long long a[maxN];
long long t[4 * maxN];
long long m;
void build(long long n,long long b,long long e)
{
    if(b==e)
    {
        t[n] = (a[b]%m);
        return;
    }
    long long mid = (b + e) / 2;         //     n
    long long l = 2 * n;                 /*    / \     */ 
    long long r = 2 * n + 1;            //    l   r
    build(l, b, mid);
    build(r, mid + 1, e);
    t[n] = ((t[l] % m) * (t[r] % m)) % m; // change this
}

void update(long long n,long long b,long long e,long long i,long long v)
{
    if(i<b || i>e)
    {
        return;
    }
    if(b==e)
    {
        t[n] = v;
        return;
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    update(l, b, mid, i, v);
    update(r, mid + 1, e, i, v);
    t[n] = ((t[l] % m) * (t[r] % m)) % m;   // change this
}

long long query(long long n,long long b,long long e,long long i,long long j)
{
    if(e<i || j<b)
    {
        return 1;        // return right value
    }
    if(b>=i && e<=j)
    {
        return t[n];
    }
    long long mid = (b + e) / 2;
    long long l = 2 * n;
    long long r = 2 * n + 1;
    return ((query(l, b, mid, i, j) % m) * (query(r, mid + 1, e, i, j) % m)) % m; // change this
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long te;
    cin >> te;
    while(te--)
    {
        long long n;
        cin >> n >> m;
        for (long long i = 1; i <= n;i++)
        {
            cin >> a[i];
        }
        build(1, 1, n);
        string s;
        cin >> s;
        vector<long long> ans;
        long long l = 1;
        long long r = n;
        for (long long i = 0; i < n;i++)
        {
            ans.push_back(query(1, 1, n, l, r) % m);
            if(s[i]=='L')
            {
                l++;
            }
            else{
                r--;
            }
        }
        for(long long i:ans)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}