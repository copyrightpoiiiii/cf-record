#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll readll(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
int power(int x,int y){
    int t=1;
    for(;y;y>>=1,x=x*x%mod)
        if(y&1)t=t*x%mod;
    return t;
}

vector<vector<int> > edge(maxn, vector<int>(0));

struct Node{
    int ch[2],d;
    ll add,mul,val;

    Node(){
        ch[0]=ch[1]=add=val=0;
        d=mul=0;
    }
} t[maxn];

int& rs(int x){return t[x].ch[t[t[x].ch[1]].d < t[t[x].ch[0]].d];}

void madd(int u,ll x){
    t[u].val += x;
    t[u].add += x;
}

void mmul(int u,ll x){
    t[u].val *= x;
    t[u].mul *= x;
    t[u].add *= x;
}

void pushdown(int x){
    mmul(t[x].ch[0], t[x].mul);
    mmul(t[x].ch[1], t[x].mul);
    madd(t[x].ch[0], t[x].add);
    madd(t[x].ch[1], t[x].add);
    t[x].add = 0;
    t[x].mul = 1;
}

int merge(int x,int y){
    if(!x || !y) return x|y;
    if(t[x].val > t[y].val) swap(x,y);
    pushdown(x);
    rs(x) = merge(rs(x), y);
    t[x].d = t[rs(x)].d + 1;
    return x;
}

int pop(int x){
    pushdown(x);
    return merge(t[x].ch[0], t[x].ch[1]);
}

int ans[maxn],ans2[maxn],dep[maxn],c[maxn],p[maxn];
ll h[maxn],a[maxn],v[maxn];
void dfs(int x){
    int sum = 0;
    while(p[x] && t[p[x]].val < h[x]){
        sum++;
        ans2[p[x]] = dep[c[p[x]]] - dep[x];
        p[x] = pop(p[x]);
    }
    for(int i=0;i<edge[x].size();i++){
        dep[edge[x][i]] = dep[x] + 1;
        dfs(edge[x][i]);
        p[x] = merge(p[edge[x][i]], p[x]);
        while(p[x] && t[p[x]].val < h[x]){
            sum++;
            ans2[p[x]] = dep[c[p[x]]] - dep[x];
            p[x] = pop(p[x]);
        }
    }
    ans[x] = sum;
    if(a[x]==0){
        madd(p[x],v[x]);
    }
    else{
        mmul(p[x],v[x]);
    }
}


void solve(){
    int n=read(),m=read();
    for(int i=1;i<=n;i++)
        h[i]=readll();
    for(int i=2;i<=n;i++){
        int fa=read();
        edge[fa].push_back(i);
        a[i]=readll();
        v[i]=readll();
    }
    for(int i=1;i<=m;i++){
        ll s=readll(),ci=readll();
        t[i].val=s;
        c[i] = ci;
        p[ci] = merge(i,p[ci]);
    }
    dfs(1);
    while(p[1]){
        ans2[p[1]] = dep[c[p[1]]]+1;
        p[1] = pop(p[1]);
    }
    for(int i=1;i<=n;i++){
        printf("%d\n",ans[i]);
    }
    for(int i=1;i<=m;i++){
        printf("%d\n",ans2[i]);
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}