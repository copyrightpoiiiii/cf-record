#include<bits/stdc++.h>
#define inf (3e18)+5
#define maxn 100000+5
#define maxm 5000000+5
#define eps 1e-10
#define ll long long
#define for0(i,n) for(int i=0;i<=(n);i++)
#define for1(i,n) for(int i=1;i<=(n);i++)
#define for2(i,x,y) for(int i=(x);i<=(y);i++)
#define for3(i,x,y) for(int i=(x);i>=(y);i--)
#define for4(i,x) for(int i=head[x],y=e[i].go;i;i=e[i].next,y=e[i].go)
using namespace std;
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int gcd(int x,int y){return y?gcd(y,x%y):x;}
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/

struct bus{
	ll a,x,id;
}t[200005];
ll n,ti,shang[200005],qizhu[200005],sum=0;
bool cmp(bus x1,bus x2){
	return x1.id<x2.id;
}
int main(){
	n=read();ti=read();
	for1(i,n){
		t[i].a=read();
	}
	for1(i,n){
		t[i].x=read();
		//cout<<t[i].x<<endl;
		if(t[i].x<i){
			cout<<"No"<<endl;
			return 0;
		}
	}
	t[n+1].a=inf+1;
	//int l=0,r
	for1(i,n){
		//ll shang=0,xia=0;
		shang[i]=t[t[i].x+1].a+ti-1;
		//cout<<shang[i]<<" s"<<endl;
		t[i].id=max(t[i-1].id+1,t[i].a+ti);
		if(i!=t[i].x){
			qizhu[t[i].a]-=1;
			qizhu[i]+=1;
		}
		//for(int j=i+1;j<=t[i].x;j++){
		//	t[j-1].id=max(t[j-1].id,t[j].a+ti);
			//cout<<t[j-1].id<<endl;
		//}
		//cout<<shang<<" "<<xia<<endl;
		//if(shang<xia){
			//
		//}
		//else t[i].id=xia;
	}
	for1(i,n)
		if(t[i].id>shang[i]){
			cout<<"No"<<endl;
			return 0;
		}
	for1(i,n){
		sum+=qizhu[i];
		//for(int j=i+1;j<=t[i].x;j++){
		//	t[j-1].id=max(t[j-1].id,t[j].a+ti);
			//cout<<t[j-1].id<<endl;
		//}
		//cout<<shang<<" "<<xia<<endl;
		//if(shang<xia){
			//
		//}
		//else t[i].id=xia;
		if(sum>0)t[i].id=max(t[i+1].a+ti,t[i].id);
		if(t[i].id>shang[i]||t[i].id>inf-5){
			cout<<"No"<<endl;
			return 0;
		}
		
	}
	//sort(t+1,t+n+1,cmp);
	cout<<"Yes"<<endl;
	for1(i,n)
		printf("%lld ",t[i].id);
	return 0;
}

