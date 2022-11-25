#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000 + 5)
int read()
{
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
ll readll()
{
    ll x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9')
    {
        if (ch == '-')
            f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = 10 * x + ch - '0';
        ch = getchar();
    }
    return x * f;
}
int gcd(int x, int y) { return y ? gcd(y, x % y) : x; }
#define mod 1000000007
struct edge
{
    ll h, l, r;
    bool flag;
};

static bool cmp(edge a, edge b)
{
    return a.h < b.h;
}

vector<long long> tree, lazy, len;
vector<long long> tmp;
int n, root;
map<ll, ll> m;

void pushup(int cl, int cr, int p)
{
    if (lazy[p] > 0)
    {
        tree[p] = len[p];
    }
    else
    {
        tree[p] = tree[p << 1] + tree[p << 1 | 1];
    }
}

void range_set(int l, int r, int cl, int cr, int p, long long val)
{
    if (l == cl && cr == r)
    {
        lazy[p] += val;
        pushup(cl, cr, p);
        return;
    }
    int m = (cl + cr) >> 1;
    if (l <= m)
        range_set(l, min(r, m), cl, m, p << 1, val);
    if (m < r)
        range_set(max(l, m + 1), r, m + 1, cr, p << 1 | 1, val);
    pushup(cl, cr, p);
}

void build(int l, int r, int p)
{
    if (l == r)
    {
        tree[p] = 0;
        len[p] = tmp[l] - tmp[l - 1];
        return;
    }
    int m = (l + r) >> 1;
    build(l, m, p << 1);
    build(m + 1, r, p << 1 | 1);
    len[p] = tmp[r] - tmp[l - 1];
    tree[p] = 0;
}

int main()
{
    int x = read();
    vector<edge> e;
    while(x--){
        vector<ll> rec;
        rec.clear();
        for(int i=1;i<=4;i++)
            rec.push_back(readll());
        tmp.push_back(rec[0]);
        tmp.push_back(rec[2]);
        e.push_back({rec[1], rec[0], rec[2], true});
        e.push_back({rec[3], rec[0], rec[2], false});
    }
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());
    n = tmp.size();
    tree.resize(8 * n + 5);
    lazy.resize(8 * n + 5);
    len.resize(8 * n + 5);
    for (int i = 1; i <= n; i++)
        m[tmp[i - 1]] = i;
    root = 1;
    build(1, n - 1, 1);
    sort(e.begin(), e.end(), cmp);
    long long ans = 0;
    range_set(m[e[0].l], m[e[0].r] - 1, 1, n - 1, 1, 1);
    // cout<< e[0].l << e[0].r<< e[0].h<<tree[root]<<endl;
    for (int i = 1; i < e.size(); i++)
    {
        ans = (ans + ((e[i].h - e[i - 1].h) * tree[root]) ) ;
        if (e[i].flag)
        {
            range_set(m[e[i].l], m[e[i].r] - 1, 1, n - 1, 1, 1);
        }
        else
            range_set(m[e[i].l], m[e[i].r] - 1, 1, n - 1, 1, -1);
        // cout<< e[i].l << e[i].r<< e[i].h<<tree[root]<<endl;
    }
    cout<< ans ;
    return 0;
}