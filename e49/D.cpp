#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 200000+5
#define maxm 200000+5
#define eps 1e-10
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
struct{
	int go,next;
}e[2*maxm];
int n,head[maxn],tot,w[maxn],book[maxn],fa[maxn],w2[maxn],b2[maxn];
int c[maxn];
ll ans;
int ind[maxn],od[maxn];
void insert(int u,int v){
	e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
}
int find(int x){
	if(fa[x]==x)return x;
	else return fa[x]=find(fa[x]);
}
void topsort(){
	int jilu[maxn],head2=1,tail=0;
	memset(jilu,0,sizeof(jilu));
	for(int i=1;i<=n;i++){
		if(od[i]==0){
					ans+=w[i];
					book[i]=1;
				}
				if(ind[i]==0){
					for(int j=head[i];j;j=e[j].next){
						ind[e[j].go]--;
						if(ind[e[j].go]==0)
							jilu[++tail]=e[j].go;
					}
					book[i]=1;
				}
	}
		
	while(head2<=tail){
		int x=jilu[head2];
		head2++;
			if(!book[x]){
				if(od[x]==0){
					ans+=w[x];
					book[x]=1;
				
				}
					for(int j=head[x];j;j=e[j].next){
						ind[e[j].go]--;
						if(ind[e[j].go]==0)
							jilu[++tail]=e[j].go;
					}
					book[x]=1;
				
			
			}
	}
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		w[i]=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
		w2[i]=w[i];
	}
	for(int i=1;i<=n;i++){
		int x=read();
		c[i]=x;
		insert(i,x);
		if(x!=i){
			ind[x]++;
			od[i]++;
		}
	}
	topsort();
	for(int i=1;i<=n;i++)
		if(!book[i]&&!book[c[i]]){
			int fx=find(i),fy=find(c[i]);
					if(fx!=fy){
						fa[fy]=fx;
						w2[fx]=min(w2[fy],w2[fx]);
						b2[fy]=1;
					}
		}
		else b2[i]=1;
	for(int i=1;i<=n;i++)
		if(!b2[i])
			ans+=w2[i];
	cout<<ans;
	return 0;
}

