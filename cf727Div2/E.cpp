#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
#define ls (i<<1)
#define rs (i<<1|1)
int read(){
    int x=0,f=1;char ch=getchar();
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
int n,m;
int a[maxn];
pair<int,int> fi[maxn];
struct info{
    int sum,mxp,mxs;
};
info merge(info a,info b){
    info tmp;
    tmp.sum = a.sum+b.sum;
    tmp.mxp = max(a.mxp,max(a.sum+b.mxp,0));
    tmp.mxs = max(b.mxs,max(b.sum+a.mxs,0));
    return tmp;
}
void update(info &a,int k){
    if(k>0)
        a.sum=a.mxp=a.mxs=k;
    else{
        a.sum=k;
        a.mxp=a.mxs=0;
    }

}
struct tree{
    int l,r;
    info  in;
}f[maxn*4];
void pushup(int i){
    f[i].in = merge(f[ls].in,f[rs].in);
}
void update(int i,int k){
    update(f[i].in,k);
}
void build(int i,int left,int right){
    int mid = (left+right)>>1;
    f[i].l=left;f[i].r=right;
    if(left == right){
        update(f[i].in,a[left]);
        return ;
    }
    build(ls,left,mid);build(rs,mid+1,right);
    pushup(i);
}
info query_max(int i,int left,int right){
    if(left>right)return (info){0,0,0};
    int mid = (f[i].l+f[i].r)>>1;
    if(f[i].l==left && f[i].r==right)return f[i].in;
    if(mid>=right)return query_max(ls,left,right);
    if(mid<left)return query_max(rs,left,right);
    return merge(query_max(ls,left,mid),query_max(rs,mid+1,right));
}
void change(int i,int pos,int val){
    if(f[i].l==f[i].r&&f[i].l==pos){
        update(i,val);
        return ;
    }
    int mid = (f[i].l+f[i].r)>>1;
    if(pos<=mid)change(ls,pos,val);
    else change(rs,pos,val);
    pushup(i);
}
int ans[maxn];
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    n=read();
    for(int i=1;i<=n;i++){
        fi[i].first=read();
        fi[i].second=i;
    }
    sort(fi+1,fi+n+1);
    for(int i=1;i<=n;i++)
        a[i]=1;
    //cout<<"s"<<endl;
    build(1,1,n);
    //cout<<"ss"<<endl;
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<n && fi[j+1].first == fi[i].first)j++;
        for(int k=i;k<=j;k++){
            ans[fi[k].second]=max(ans[fi[k].second],(query_max(1,1,fi[k].second).mxs+query_max(1,fi[k].second+1,n).mxp)/2);
        }
        for(int k=i;k<=j;k++)
            change(1,fi[k].second,-1);
        i=j;
    }
    memset(f,0,sizeof(f));
    for(int i=1;i<=n;i++)
        a[i]=-1;
    build(1,1,n);
    for(int i=1;i<=n;i++){
        int j=i;
        while(j<n&&fi[j+1].first == fi[i].first)j++;
        for(int k=i;k<=j;k++)
            change(1,fi[k].second,1);
        for(int k=i;k<=j;k++){
            ans[fi[k].second]=max(ans[fi[k].second],(query_max(1,1,fi[k].second).mxs+query_max(1,fi[k].second+1,n).mxp-1)/2);
        }
        i=j;
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}