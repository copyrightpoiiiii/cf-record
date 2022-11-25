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
int abs(int x){
    return x>0?x:-x;
}
void solve(){
    int x=read(),y=read();
    if ((x+y)%2==1){
        printf("-1 -1\n");
        return ;
    }
    else{
        int maxx = (x+y)/2;
        for(int i=-maxx;i<=maxx;i++){
            int tmp = (x+y)/2 - abs(i);
            if(abs(i-x)+abs(tmp-y) == ((x+y)/2)){
                printf("%d %d\n",i,tmp);
                return ;
            }
            tmp = -tmp;
            if(abs(i-x)+abs(tmp-y) == ((x+y)/2)){
                printf("%d %d\n",i,tmp);
                return ;
            }
        }
    }
    printf("-1 -1\n");
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T=read();
    while (T--){
        solve();
    }
    return 0;
}