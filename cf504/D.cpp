#include<bits/stdc++.h>
#define inf 1000000000
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
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int a[200005];
int head[200005];
int tot;
struct sega{
	int head,tail,next;
}e[200005];
int num[200005];
struct tree{
    int l,r,mi;
}f[200005*4];
int n,q,book[200005];
void pushup(int i){
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}
  
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].mi=200005;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].mi=a[left];
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
 
int qmax(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    if(mid>=right) return qmax(i*2,left,right);
    if(mid<left) return qmax(i*2+1,left,right);
    return min(qmax(i*2,left,mid),qmax(i*2+1,mid+1,right));
}
int main(){
	n=read();q=read();
	int sz=0;
	int last=0;
	for(int i=1;i<=n;i++){
		a[i]=read();
		book[a[i]]++;
		if(a[i]>q){
			cout<<"NO"<<endl;
			return 0;
		}
		if(a[i]==0&&sz==0)sz=i;
		//if(a[i]==0)a[i]=a[i-1];
		if(a[i]!=a[last]){
			num[a[last]]++;
			e[++tot].head=last;
			e[tot].tail=i-1;
			e[tot].next=head[a[last]];
			head[a[last]]=tot;
			last=i;
		}
	}
	num[a[last]]++;
	e[++tot].head=last;
	e[tot].tail=n;
	e[tot].next=head[a[last]];
	head[a[last]]=tot;
	if(book[q]==0&&sz==0){
		cout<<"NO"<<endl;
		return 0;
	}
	else if(book[q]==0)a[sz]=q;
	a[n+1]=q;
	int now=1;
	while(a[now]==0)
		now++;
	while(now){
		a[now-1]=a[now];
		now--;
	}
	for(int i=1;i<=n;i++)
		if(a[i]==0)
			a[i]=a[i-1];
	build(1,1,n);
	
	for(int i=q;i>0;i--){
		int flag=0;
		for(int j=head[i];j;j=e[j].next){
			int st,ed=e[j].head;
			st=e[e[j].next].tail;
			//cout<<i<<" "<<st<<" "<<ed<<endl;
			if(st<ed&&st){
				//cout<<i<<" "<<st<<" "<<ed<<endl;
				int tmp=qmax(1,st,ed);
				if(tmp<i){
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"NO"<<endl;
			return 0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)
		printf("%d ",a[i]);
	return 0;
}
