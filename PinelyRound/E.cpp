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
/*int n,m,tot,head[maxn];
struct edge{
    int go,next;
}e[maxn*2];
void insert(int u,int v){
    e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
    e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}*/
int v[4005],blockNum;
int ind[4005];
int fa[4005];
int s[4005];
int find(int x){
    return fa[x]==x?x:fa[x]=find(fa[x]);
}
void merge(int x,int y){
    int fax = find(x), fay = find(y);
    if(fax==fay){
        return;
    }
    blockNum--;
    if(s[fax]<s[fay]){
        s[fay] += s[fax];
        fa[fax] = fay;
    } else{
        s[fax] += s[fay];
        fa[fay] = fax;
    }
}
void solve(){
    int n ;
    cin>>n;
    vector<int> edge[4005];
    memset(ind, 0, sizeof(ind));
    for(int i=1;i<=n;i++){
        fa[i]=i;
        s[i]=1;
    }
    blockNum = n;
    for(int i=1;i<=n;i++){
        string tmp;
        cin>>tmp;
        for(int j=0;j<n;j++)
            if(tmp[j]=='1'){
                edge[i].push_back(j+1);
                merge(i,j+1);
                ind[i]++;
            }
    }
    if(blockNum==1){
        cout<<0<<endl;
        return;
    }
    int minSize=n*2,minid=0;
    for(int i=1;i<=n;i++){
        int f = find(i);
        if(ind[i]!=s[f]-1){   
            int minind=n*3,ans=0;
            for(int j=1;j<=n;j++)
                if(find(j)==f){
                    if(minind>ind[j]){
                        minind = ind[j];
                        ans=j;
                    }
                }
            cout<<1<<endl<<ans<<endl;
            return;
        }
        if(s[f]<minSize){
            minSize= s[f];
            minid = f;
        }
    }
    if(minSize==1){
        cout<<1<<endl<<minid<<endl;
        return;
    }
    if(blockNum==2){
        cout<<minSize<<endl;
        for(int i=1;i<=n;i++)
            if(minid == find(i))
                cout<<i<<' ';
        cout<<endl;
    } else{
        cout<<2<<endl;
        cout<<minid<<" ";
        for(int i=1;i<=n;i++)
            if(find(i)!=minid){
                cout<<i<<endl;
                return;
            }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T ;
    cin>>T;
    while(T--){
        solve();
    }
    return 0;
}