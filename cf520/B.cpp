#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define mod 1000000007
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
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
/*
struct edge{
	int go,next;
}
void insert(int u,int v){
	 e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}
*/
int n,cnt;
int prime[1000001];
bool vis[1000001];
int ji[1000005];
int main(){
	n=read();
	if(n==1){
		cout<<1<<" "<<0<<endl;
		return 0;
	}
	for(int i = 2; i <= n; i++)
    {
        if(!vis[i])
        prime[cnt++] = i;
        for(int j = 0; j<cnt && i*prime[j]<=n; j++)
        {
            vis[i*prime[j]] = true;
            if(i % prime[j] == 0) break;
        }
    }
    //cout<<"sss"<<endl;
    int tmp=n;
    for(int i=0;i<cnt;i++){
    	//cout<<tmp<<" "<<prime[i]<<endl;
		while(tmp%prime[i]==0){
			ji[i]++;
			tmp/=prime[i];
			if(tmp==1)break;
		}
		if(tmp==1)break;
	}
	int mx=0;
	ll ans1=1;
	int flag=0;
	//cout<<"ss"<<endl;
	for0(i,cnt-1)
		if(ji[i]>0){
		mx=max(mx,ji[i]);
		if(ji[i]!=mx)flag=1;
		ans1*=prime[i];
	}
	ll now=1,ans=0;
	while(mx>now){
		now*=2;
		ans++;
	}
	if(now!=mx)flag=1;
	cout<<ans1<<" "<<ans+flag<<endl;
	return 0;
}


