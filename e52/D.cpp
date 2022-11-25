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
pair<int,int> f[105][105][4];
pair<int,int> mp[105];
int n,a[105][105];
pair<int,int> operator+(pair<int,int> a,pair<int,int> b){
	pair<int,int> ans;
	ans.first=a.first+b.first;
	ans.second=a.second+b.second;
	return ans;
}
pair<int,int> min_p(pair<int,int> a,pair<int,int> b){
	if(b.second<a.second)return b;
	else if(b.second>a.second)return a;
	if(b.first<a.first)return b;
	else return a;
}
int main(){
	n=read();
	for1(i,n)
		for1(j,n){
			a[i][j]=read();
			mp[a[i][j]]=make_pair(i,j);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			{
				f[i][j][1]=make_pair(inf,inf);
				f[i][j][2]=make_pair(inf,inf);
				f[i][j][3]=make_pair(inf,inf);
			}
	f[mp[1].first][mp[1].second][1]=make_pair(0,0);
	f[mp[1].first][mp[1].second][2]=make_pair(0,0);
	f[mp[1].first][mp[1].second][3]=make_pair(0,0);
	for(int i=1;i<=n*n;i++)
		for(int j=1;j<=i;j++){
			int xi=mp[i].first,yi=mp[i].second;
			if(xi-1>=1){
				if(yi+2<=n)
					if(i>a[xi-1][yi+2]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi+2][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi+2][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi+2][3]+make_pair(1,1));
					}
				if(yi-2>=1)
					if(i>a[xi-1][yi-2]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi-2][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi-2][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-1][yi-2][3]+make_pair(1,1));
					}
			}
			if(xi+1<=n){
				if(yi+2<=n)
					if(i>a[xi+1][yi+2]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi+2][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi+2][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi+2][3]+make_pair(1,1));
					}
				if(yi-2>=1)
					if(i>a[xi+1][yi-2]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi-2][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi-2][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+1][yi-2][3]+make_pair(1,1));
					}
			}
			if(xi-2>=1){
				if(yi+1<=n)
					if(i>a[xi-2][yi+1]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi+1][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi+1][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi+1][3]+make_pair(1,1));
					}
				if(yi-1>=1)
					if(i>a[xi-2][yi-1]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi-1][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi-1][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi-2][yi-1][3]+make_pair(1,1));
					}
			}
			if(xi+2<=n){
				if(yi+1<=n)
					if(i>a[xi+2][yi+1]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi+1][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi+1][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi+1][3]+make_pair(1,1));
					}
				if(yi-1>=1)
					if(i>a[xi+2][yi-1]){
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi-1][1]+make_pair(1,0));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi-1][2]+make_pair(1,1));
						f[xi][yi][1]=min_p(f[xi][yi][1],f[xi+2][yi-1][3]+make_pair(1,1));
					}
			}
			for(int k=1;k<=n;k++){
				if(a[xi][k]<i){
					f[xi][yi][2]=min_p(f[xi][yi][2],f[xi][k][1]+make_pair(1,1));
					f[xi][yi][2]=min_p(f[xi][yi][2],f[xi][k][2]+make_pair(1,0));
					f[xi][yi][2]=min_p(f[xi][yi][2],f[xi][k][3]+make_pair(1,1));
				}
				if(a[k][yi]<i){
					f[xi][yi][2]=min_p(f[xi][yi][2],f[k][yi][1]+make_pair(1,1));
					f[xi][yi][2]=min_p(f[xi][yi][2],f[k][yi][2]+make_pair(1,0));
					f[xi][yi][2]=min_p(f[xi][yi][2],f[k][yi][3]+make_pair(1,1));
				}
			}
			int tmpx=xi+1,tmpy=yi+1;
			while(tmpx<=n&&tmpy<=n){
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][1]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][2]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][3]+make_pair(1,0));
				tmpx++;tmpy++;
			}
			tmpx=xi+1;tmpy=yi-1;
			while(tmpx<=n&&tmpy>=1){
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][1]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][2]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][3]+make_pair(1,0));
				tmpx++;tmpy--;
			}
			tmpx=xi-1;tmpy=yi+1;
			while(tmpx>=1&&tmpy<=n){
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][1]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][2]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][3]+make_pair(1,0));
				tmpx--;tmpy++;
			}
			tmpx=xi-1;tmpy=yi-1;
			while(tmpx>=1&&tmpy>=1){
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][1]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][2]+make_pair(1,1));
				f[xi][yi][3]=min_p(f[xi][yi][3],f[tmpx][tmpy][3]+make_pair(1,0));
				tmpx--;tmpy--;
			}
		}
		pair<ll,ll> ans=min_p(f[mp[n*n].first][mp[n*n].second][1],f[mp[n*n].first][mp[n*n].second][2]);
		ans=min_p(ans,f[mp[n*n].first][mp[n*n].second][3]);
		cout<<ans.first<<" "<<ans.second<<endl;
	return 0;
}


