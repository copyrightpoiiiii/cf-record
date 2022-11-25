#include<bits/stdc++.h>
#define maxn (500000 + 5)
#define maxm (500000 + 5)
#define eps (1e-10)
#define mod (1000000007)
#define ll long long
#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, r, l) for (int i = (r); i >= (l); i--)
#define pr1(i,x) cout<<i<<" "<<x<<endl
#define pr(x) cout<<x<<endl;
#define sqr(x) ((x) * (x))
#define pa pair<int, int>
using namespace std;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
const int dxo[8] = {-1, -1, -1, 0, 1, 1, 1, 0};
const int dyo[8] = {-1, 0, 1, 1, 1, 0, -1, -1};
const int inf = 1000000000;
const ll inf_ll = (ll)1 << 60;
inline bool is_down(char x) { return ('a' <= x && x <= 'z'); }
inline bool is_upper(char x) { return ('A' <= x && x <= 'Z'); }
inline bool is_digit(char x) { return ('0' <= x && x <= '9'); }
long long gcd(long long x,long long y){return y?gcd(y,x%y):x;}
long long exgcd(long long a, long long b, long long &x, long long &y)
{
    if (!b)
    {
        x = 1;
        y = 0;
        return a;
    }
    else
    {
        long long tx, ty;
        long long d = exgcd(b, a % b, tx, ty);
        x = ty;
        y = tx - (a / b) * ty;
        return d;
    }
}
long long power(long long x,long long y){
    long long t=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)t=t*x%mod;
    return t;
}
struct segment_tree
{
    struct seg
    {
        int l, r;
        int mi, mx, sum;
    } t[4 * maxn];
    void pushup(int k)
    {
        t[k].mi = min(t[k << 1].mi, t[k << 1 | 1].mi);
        t[k].mx = max(t[k << 1].mx, t[k << 1 | 1].mx);
        t[k].sum = t[k << 1].sum + t[k << 1 | 1].sum;
    }
    inline void build(int k, int l, int r)
    {
        t[k].l = l;
        t[k].r = r;
        int mid = (l + r) >> 1;
        t[k].mi = inf;
        if (l == r)
        {
            t[k].mi = t[k].mx = t[k].sum = 0;
            return;
        }
        build(k << 1, l, mid);
        build(k << 1 | 1, mid + 1, r);
        pushup(k);
    }
    inline void change_point(int k, int x, int y)
    {
        int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
        if (l == r)
        {
            t[k].mi = t[k].mx = t[k].sum = y;
            return;
        }
        if (x <= mid)
            change_point(k << 1, x, y);
        else
            change_point(k << 1 | 1, x, y);
        pushup(k);
    }
    inline int query_sum(int k, int x, int y)
    {
        int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
        if (l == x && r == y)
            return t[k].sum;
        if (y <= mid)
            return query_sum(k << 1, x, y);
        else if (x > mid)
            return query_sum(k << 1 | 1, x, y);
        else
            return query_sum(k << 1, x, mid) + query_sum(k << 1 | 1, mid + 1, y);
    }
    inline int query_min(int k, int x, int y)
    {
        int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
        if (l == x && r == y)
            return t[k].mi;
        if (y <= mid)
            return query_min(k << 1, x, y);
        else if (x > mid)
            return query_min(k << 1 | 1, x, y);
        else
            return min(query_min(k << 1, x, mid), query_min(k << 1 | 1, mid + 1, y));
    }
    inline int query_max(int k, int x, int y)
    {
        int l = t[k].l, r = t[k].r, mid = (l + r) >> 1;
        if (l == x && r == y)
            return t[k].mx;
        if (y <= mid)
            return query_max(k << 1, x, y);
        else if (x > mid)
            return query_max(k << 1 | 1, x, y);
        else
            return max(query_max(k << 1, x, mid), query_max(k << 1 | 1, mid + 1, y));
    }
};
struct union_set{
    int fa[maxn];
    int s[maxn];
    int setNum;
    void init(int n){
        setNum = n;
        rep(i,1,n){
            fa[i]=i;
            s[i]=1;   
        }
    }
    int find(int x) {return fa[x]==x?x:fa[x]=find(fa[x]);}
    void merge(int x,int y){
        int fx = find(x), fy=find(y);
        if(fx==fy)
            return;
        setNum--;
        if(s[fx]>s[fy]){
            s[fx] += s[fy];
            fa[fy] = fx;
        } else{
            s[fy] += s[fx];
            fa[fx] = fy;
        }
    }
};
int c[maxn];
void solve(){
    int n;
    cin>>n;
    string a,b;
    cin>>a>>b;
    rep(i,0,n-1){
        int x=a[i]-'0',y=b[i]-'0';
        c[i]=x^y;
    }
    rep(i,1,n-1)
        if(c[i]!=c[i-1]){
            pr("NO");
            return;
        }
    int sum=0;
    vector<pa > op;
    rep(i,0,n-1)
        if(a[i]=='1'){
            sum++;
            op.emplace_back(i+1,i+1);
        }
    if(sum%2!=c[0]){
        sum+=3;
        op.emplace_back(1,1);
        op.emplace_back(2,n);
        op.emplace_back(1,n);
    }
    pr("YES");
    pr(sum);
    for(auto x:op){
        pr1(x.first,x.second);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}