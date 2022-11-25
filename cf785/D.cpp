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
ll gcd(ll x,ll y){return y?gcd(y,x%y):x;}
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
ll prime[40005],tof[40005],tot;

ll check(ll a,ll b){
    ll gc = gcd(a,b);
    return a*b/gc;
}

void solve(){
    ll b=readll(),q=readll(),y=readll();
    ll c=readll(),r=readll(),z=readll();
    if(r%q!=0){
        printf("0\n");
        return;
    }
    else{
        ll minb=b,maxb=b+q*(y-1);
        ll minc=c,maxc=c+r*(z-1);
        if(!(minb<=minc&&maxb>=maxc)){
            printf("0\n");
            return;
        }
        if((minc-minb)%q!=0 || (maxb-minc)%q!=0 ){
            printf("0\n");
            return;
        }
        if((minc-r)<minb || (maxc+r)>maxb){
            printf("-1\n");
            return;
        }
        ll sum=0;
        for(int i=0;i<tot;i++)
            if(prime[i]*prime[i]<=r){
                if(r%prime[i] == 0){
                    ll a1 = prime[i], a2 = r/prime[i];
                    if(check(a1,q) == r ){
                        sum = (sum + (a2*a2)%1000000007 ) %1000000007;
                    }
                    if(check(a2,q) == r && a1 != a2){
                        sum = (sum + (a1*a1)%1000000007 ) %1000000007;
                    }
                }
            }
            else{
                break;
            }
        cout<<sum<<endl;
        return ;
    }
}
void getprime(){
    prime[tot++]=1;
    for(int i=2;i<=32000;i++){
        if(!tof[i]){
            tof[i] = 1;
            prime[tot++]=i;
        }
        for(int j = 0;j<tot&&i*prime[j]<=32000;j++){
            tof[i*prime[j]] = 1;
            if(i%prime[j]==0)break;
        }
    }
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = read();
    getprime();
    while(T--){
        solve();
    }
    return 0;
}