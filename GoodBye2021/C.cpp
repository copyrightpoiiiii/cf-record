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
double a[100];

void solve(){
    int n =read();
    memset(a,0,sizeof(a));
    for(int i =1;i<=n;i++)
        a[i]=double(read());
    int ans = 9000;
    if(n<=2){
        cout<<0<<endl;
        return;
    }
    for(int i=1;i<=n;i++)
        for(int j=i+1;j<=n;j++){
            double cha = double(a[j]-a[i])/(j-i);
            double fis = a[i]-cha*(i-1);
            int tot=0;
            for(int k = 1;k<=n;k++ ){
                if(fabs(fis-a[k])>=1e-7)
                    tot++;
                fis+=cha;
            }
            if(tot<ans)
                ans=tot;
        }
    cout<<ans<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}