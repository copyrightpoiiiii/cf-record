#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (100000+5)
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
int n;
ll m;
ll c[maxn];

vector<vector<int> > edge(maxn, vector<int>(0));

struct Node{
    int ch[2],d;
    int size;
    ll val,sum;
} t[maxn];

int& rs(int x){return t[x].ch[t[t[x].ch[1]].d < t[t[x].ch[0]].d];}

int merge(int x,int y){
    if(!x || !y) return x|y;
    if(t[x].val > t[y].val) swap(x,y);
    rs(x) = merge(rs(x), y);
    t[x].sum = t[t[x].ch[0]].sum + t[t[x].ch[1]].sum + t[x].val;
    t[x].size = 1 + t[t[x].ch[0]].size + t[t[x].ch[1]].size;
    t[x].d = t[rs(x)].d + 1;
    return x;
}

int pop(int x){
    return merge(t[x].ch[0], t[x].ch[1]);
}

ll ans = 0;

int dfs(int x){
    if(edge[x].size() == 0){
        ans = max(ans, -t[x].val>m?0:c[x]);
    }
    int treeRoot = x;
    for(int i=0;i<edge[x].size();i++){
        treeRoot = merge(dfs(edge[x][i]), treeRoot);
        while(-t[treeRoot].sum > m){
            treeRoot = pop(treeRoot);
        }
        ans = max(ans, c[x]*t[treeRoot].size);
    }
    return treeRoot;
}

void solve(){
    n=read();m=readll();
    int root=0;
    for(int i=1;i<=n;i++){
        int fa = read();
        t[i].val = t[i].sum = -readll();
        t[i].size=1;
        c[i]=readll();
        if(!fa){
            root = i;
        }
        else{
            edge[fa].push_back(i);
        }
    }
    dfs(root);
    cout<<ans<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    solve();
    return 0;
}