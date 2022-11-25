#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<iostream>
#include<cmath>
#define inf 1000000000
#define maxn 300000+5
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
ll n,x1,x2;
ll b[maxn],c[maxn];
struct dat{
	ll w;
	int id;
}a[maxn];
ll j11[maxn],j21[maxn];
bool cmp(dat x,dat y){
	return x.w<y.w;
}
struct tree{
    ll l,r,mx;
}f[4*maxn];
 
void pushup(int i){
    f[i].mx=max(f[i*2+1].mx,f[i*2].mx);
}
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].mx=0;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].mx=j21[left];
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
 
int qmax(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mx;
    if(mid>=right) return qmax(i*2,left,right);
    if(mid<left) return qmax(i*2+1,left,right);
    return max(qmax(i*2,left,mid),qmax(i*2+1,mid+1,right));
}
int main(){
	n=read();x1=read();x2=read();
	for(int i=1;i<=n;i++){
		a[i].id=i;
		a[i].w=read();
	}
	//	a[i]=read();
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=n;i++){
		//int s1=ceil((long double)x1/a[i]),s2=ceil((long double)x2/a[i]);
		b[i]=ceil((long double)x1/a[i].w);
		if(b[i]<=n-i+1)j11[i]=i;
		c[i]=ceil((long double)x2/a[i].w);
		if(c[i]<=n-i+1)j21[i]=i;
	}
	//cout<<"sss"<<endl;
	build(1,1,n);
	//cout<<"sss"<<endl;
	for(int i=1;i<=n;i++){
		if(j11[i]){
			int tmp=qmax(1,i+b[i],n),tmp2=qmax(1,1,max(1,i-1));
			if(tmp){
				printf("Yes\n");
				printf("%d %d\n",b[i],c[tmp]);
				for(int j=i;j<=i+b[i]-1;j++){
					printf("%d ",a[j].id);
				}
				printf("\n");
				for(int j=tmp;j<=c[tmp]+tmp-1;j++){
					printf("%d ",a[j].id);
				}
				return 0;
			}
			else if(tmp2){
				printf("Yes\n");
				printf("%d %d\n",b[i],c[tmp2]);
				for(int j=i;j<=i+b[i]-1;j++){
					printf("%d ",a[j].id);
				}
				printf("\n");
				for(int j=tmp2;j<=tmp2+c[tmp2]-1;j++){
					printf("%d ",a[j].id);
				}
				return 0;
			}
		}
	}
	cout<<"No"<<endl;
	return 0;
}

