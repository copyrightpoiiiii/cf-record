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
ll su(ll x){
    return (1+x)*x/2;
}
void solve(){
    ll x,k;
    cin>>k>>x;
    if((1+k)*k == x*2){
        printf("%lld\n",k);
        return ;
    }
    if(su(k)+su(k-1) <= x){
        printf("%lld\n",k*2-1);
        return;
    }
    if((1+k)*k > x*2){
        ll l = 1,r=k;
        while(l<=r){
            ll mid = (l+r)>>1;
            ll tmp = (mid+1)*mid/2;
            if(tmp >=x){
                r=mid-1;
            }
            else l=mid+1;
        }
        while(su(l)<x)
            l++;
        printf("%lld\n",l);
    }
    else{
        x-=su(k);
        ll l=1,r=k;
        while(l<=r){
            ll mid = (l+r)>>1;
            ll tmp =su(k-1)- su(k-1-mid);
            if(tmp >=x){
                r=mid-1;
            }
            else l=mid+1;
        }
        while((su(k-1)-su(k-1-l))<x)
            l++;
        printf("%lld\n",k+l);
    }

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