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
void solve(){
    string s;
    cin>>s;
    int sum[30],diff=0;
    memset(sum,0,sizeof(sum));
    for(int i=0;i<s.length();i++)
        if(!sum[s[i]-'a']){
            sum[s[i]-'a']=1;
            diff++;
        }
    memset(sum,0,sizeof(sum));
    for(int i=0;i<diff;i++)
        if(!sum[s[i]-'a']){
            sum[s[i]-'a']++;
        }
        else{
            printf("NO\n");
            return ;
        }
    for(int i=diff;i<s.length();i++)
        if(s[i%diff]!=s[i]){
            printf("NO\n");
            return ;
        }
    printf("YES\n");
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