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
int n,k;
int mp[2005][2005];
int d[2005][2005];
int rak[2005][2005];
int pa[2005][2005];
struct jil{
	int x,y;
	int a,b;
}t[4005];
int ansdis=0,ansj=0,ansrk=inf,ansi=1;
bool cmp(jil x,jil y){
	if(x.a==y.a){
		return x.b<y.b;
	}
	else return x.a<y.a;
}
int main(){
	n=read();k=read();
	memset(rak,0x3f,sizeof(rak));
	for1(i,n)
		for1(j,n){
			char ch=getchar();
			while(ch<'a'||ch>'z')ch=getchar();
			mp[i][j]=ch-'a'+1;
		}
	for1(i,n)
		for1(j,n){
			d[i][j]=max(d[i-1][j],d[i][j-1]);
			if(mp[i][j]==1)
				d[i][j]++;
		}
	for(int i=2*n;i>=1;i--){
		memset(t,0,sizeof(t));
		int tmp,now=0;
		for(int j=1;j<=i;j++){
			if(i-j<=0||i-j>n||j>n)
				continue;
			else{
				tmp=i-j;
				//cout<<j<<" "<<tmp<<" "<<rak[j+1][tmp]<<" "<<rak[j][tmp+1]<<endl;
				if(rak[j+1][tmp]>=rak[j][tmp+1])
					pa[j][tmp]=0;
				else pa[j][tmp]=1;
				t[++now].a=mp[j][tmp];
				t[now].b=min(rak[j+1][tmp],rak[j][tmp+1]);
				t[now].x=j;
				t[now].y=tmp;
			}
		}
		sort(t+1,t+now+1,cmp);
		rak[t[1].x][t[1].y]=1;
		for(int j=2;j<=now;j++)
			if(t[j].a==t[j-1].a&&t[j].b==t[j-1].b)
				rak[t[j].x][t[j].y]=rak[t[j-1].x][t[j-1].y];
			else rak[t[j].x][t[j].y]=rak[t[j-1].x][t[j-1].y]+1;
	}
	
	for1(i,n)
		for1(j,n){
			if(i+j-1<=d[i][j]+k){
				if(i+j-1>ansdis){
					ansi=i;ansj=j;
					ansdis=i+j-1;ansrk=rak[i][j];
				}
				else if(i+j-1==ansdis&&rak[i][j]<ansrk){
					ansi=i;ansj=j;
					ansdis=i+j-1;ansrk=rak[i][j];
				}
			}
		}
	for(int i=1;i<=ansdis;i++)
		cout<<"a";
	//cout<<ansi<<" "<<ansj<<endl;
	int nowx=ansi,nowy=ansj;
	while(nowx<=n&&nowy<=n){
		if(pa[nowx][nowy]==0)
			nowy++;
		else nowx++;
		if(nowx<=n&&nowy<=n)
			cout<<(char)('a'+mp[nowx][nowy]-1);
	}
	return 0;
}


