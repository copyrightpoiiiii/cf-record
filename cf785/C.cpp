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
int a[20001];
int dp[40005];
int sum=0;
bool check(int i){
    if(i<10)
        return true;
    vector<int> dig;
    while(i){
        dig.push_back(i%10);
        i/=10;
    }
    for(int j = 0;j<dig.size()/2;j++)
        if(dig[j]!=dig[dig.size()-1-j])
            return false;
    return true;
}
void solve(){
    int n = read();
    cout<<dp[n]<<endl;
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = read();
    
    for(int i =1;i<=40000;i++)
        if(check(i)){
            a[sum++]=i;
        }
    dp[0]=1;
    for(int i=0;i<sum;i++)
        for(int j=a[i];j<=40000;j++)
            dp[j]=(dp[j-a[i]]+dp[j])%1000000007;
    while(T--){
        solve();
    }
    return 0;
}