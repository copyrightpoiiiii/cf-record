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
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll st[maxn],el[maxn];
ll n,m,v,c1,c2,q;
int main(){
	n=read();m=read();c1=read();c2=read();v=read();
	st[0]=el[0]=-1000;st[c1+1]=el[c2+1]=m+1000;
	for(int i=1;i<=c1;i++)
		st[i]=read();
	for(int i=1;i<=c2;i++)
		el[i]=read();
	//cout<<el[1]<<endl;
	q=read();
	for(int i=1;i<=q;i++){
		ll x1=read(),y1=read(),x2=read(),y2=read();
		if(y1>y2){
			//swap(x1,x2);
			swap(y1,y2);
		}
		ll ans1=(ll)2*(n+m)+1000;
		int f1=0,f2=0;
		int l=1,r=c1;
		if(c1){
		while(l<=r){
			int mid=(l+r)>>1;
			if(st[mid]==y1){
				f1=mid;
				break;
			}
			if(st[mid]>y1)
				r=mid-1;
			else l=mid+1;
		}
		if(!f1)f1=l;
		l=1,r=c1;
		while(l<=r){
			int mid=(l+r)>>1;
			if(st[mid]==y2){
				f2=mid;
				break;
			}
			if(st[mid]>y2)
				r=mid-1;
			else l=mid+1;
		}
		if(!f2)f2=l;
		//cout<<f1<<" "<<f2<<endl;
		
		if(st[f1]<y1)f1++;
		//if(st[f2]>y2)f2--;
		//cout<<abs(x1-x2)<<" "<<abs(y1-y2)<<endl;
		if(y1<=st[f1]&&st[f1]<=y2)
			ans1=abs(x1-x2)+abs(y1-y2);
		else{
			while(st[f1]>y1)f1--;
			ll tmp1=abs(x1-x2)+abs(st[f1]-y1)+abs(st[f1]-y2);
			ll tmp2=abs(x1-x2)+abs(st[f2]-y1)+abs(st[f2]-y2);
			//cout<<st[f1]<<" "<<st[f2]<<endl;
			ans1=min(ans1,min(tmp1,tmp2));
		}
	}
		//cout<<ans1<<endl;
		if(c2){
		f1=0,f2=0;
		l=1,r=c2;
		while(l<=r){
			int mid=(l+r)>>1;
			if(el[mid]==y1){
				f1=mid;
				break;
			}
			if(el[mid]>y1)
				r=mid-1;
			else l=mid+1;
		}
		if(!f1)f1=l;
		l=1,r=c2;
		while(l<=r){
			int mid=(l+r)>>1;
			if(el[mid]==y2){
				f2=mid;
				break;
			}
			if(el[mid]>y2)
				r=mid-1;
			else l=mid+1;
		}
		if(!f2)f2=l;
		if(el[f1]<y1)f1++;
		//if(st[f2]>y2)f2--;
		//cout<<
		if(y1<=el[f1]&&el[f1]<=y2)
			ans1=min(ans1,(ll)ceil((long double)abs(x1-x2)/v)+abs(y1-y2));
		else{
			while(el[f1]>y1)f1--;
			ll tmp1=ceil((long double)abs(x1-x2)/v)+abs(el[f1]-y1)+abs(el[f1]-y2);
			ll tmp2=ceil((long double)abs(x1-x2)/v)+abs(el[f2]-y1)+abs(el[f2]-y2);
			//cout<<el[f1]<<" "<<el[f2]<<" "<<tmp1<<" "<<tmp2<<endl;
			ans1=min(ans1,min(tmp1,tmp2));
		}
	}
		printf("%lld\n",ans1);
	}
	return 0;
}

