#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<cstring>
#define MAX 100010
#define inf 100000000
using namespace std;
int a[MAX];
struct tree{
    int l,r,sum,mx,mi,lazy;
}f[MAX*4];
 int n,m,r;
 int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
void pushup(int i){
    f[i].sum=(f[i*2+1].sum+f[i*2].sum);
    f[i].mx=max(f[i*2+1].mx,f[i*2].mx);
    f[i].mi=min(f[i*2+1].mi,f[i*2].mi);
}
 
void update(int i,int x)
{
    f[i].sum+=x*(f[i].r-f[i].l+1);
    f[i].mi+=x;
    f[i].mx+=x;
    f[i].lazy+=x;
    return;
}
 
void pushdown(int i){
    if(f[i].lazy!=0){
        update(i*2,f[i].lazy);
        update(i*2+1,f[i].lazy);
        f[i].lazy=0;
        return;
    }
    else return;
}
 
void build(int i,int left,int right){
    int mid=(left+right)/2;
    f[i].lazy=0;f[i].mx=0;f[i].mi=inf;
    f[i].l=left;f[i].r=right;
    if(left==right){
        f[i].sum=a[left];
        f[i].mx=a[left];
        f[i].mi=a[left];
        return;
    }
    build(i*2,left,mid);
    build(i*2+1,mid+1,right);
    pushup(i);
}
 
void add(int i,int left,int right,int v){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right){
        update(i,v);
        return;
    }
    pushdown(i);
    if(mid>=right)add(i*2,left,right,v);  
    else if(mid<left)add(i*2+1,left,right,v);
    else add(i*2,left,mid,v),add(i*2+1,mid+1,right,v);
    pushup(i);
}
 
int query(int i,int left,int right) {
        int mid=(f[i].l+f[i].r)/2;
        if(f[i].l==left&&f[i].r==right) return f[i].sum;
        pushdown(i);
        if(mid>=right) return query(i*2,left,right);
        if(mid<left) return query(i*2+1,left,right);
        return (query(i*2,left,mid)+query(i*2+1,mid+1,right));
}
 
int qmax(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mx;
    pushdown(i);
    if(mid>=right) return qmax(i*2,left,right);
    if(mid<left) return qmax(i*2+1,left,right);
    return max(qmax(i*2,left,mid),qmax(i*2+1,mid+1,right));
}

int qmin(int i,int left,int right){
    int mid=(f[i].l+f[i].r)/2;
    if(f[i].l==left&&f[i].r==right) return f[i].mi;
    pushdown(i);
    if(mid>=right) return qmin(i*2,left,right);
    if(mid<left) return qmin(i*2+1,left,right);
    return min(qmin(i*2,left,mid),qmin(i*2+1,mid+1,right));
}
int main(){
	n=read();m=read();r=read();
	for(int i=1;i<=n;i++)
		a[i]=read();
	build(1,1,n);
	for(int i=1;i<=m;i++){
		int x=read();
		printf("%d ",qmax(1,max(1,x-r),min(n,x+r)));
	}
}
