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
int a[105];
int sum[105];
int len;
int ans;
void xiao(int now){
    for(int i=now;i<len;i++)
        a[i]=a[i+1];
}
void solve(){
    int n=read();
    memset(a,0,sizeof(a));
    for(int i=1;i<=n;i++)
        a[i]=read();
    len=n;
    ans=0;
    while(len){
        int flag=1;
        int now=0,si=0;
        memset(sum, 0 ,sizeof(sum));
        for(int i=1;i<=len;i++)
            sum[a[i]]++;
        for(int i=1;i<=len;i++){
            int l = i==1?a[len]:a[i-1];
            int r = i==len?a[1]:a[i+1];
            if(l!=r){
                flag = 0;
                if(sum[a[i]]>si){
                    si = sum[a[i]];
                    now = i;
                }
            }
        }
        if(!flag){
            xiao(now);
            ans++;
            len--;
            if(len==1){
                ans++;
                break;
            }
        }
        else{
            xiao(len);
            ans++;
            len--;
            if(len==1){
                ans++;
                break;
            }
            int you=1;
            while(you){
                for(int i=1;i<=len;i++){
                    int r = i==len?a[1]:a[i+1];
                    if(a[i]==r){
                        you=0;
                        xiao(i);
                        len--;
                        break;
                    }
                }
                you^=1;
                if(len==1){
                    ans++;
                    break;
                }
            }
        }
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