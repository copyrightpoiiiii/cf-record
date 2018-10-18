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
double ra,rb,l;
double pi=acos(-1);
double fabs(double a){
	return a>=0?a:-a;
}
double fmax(double a,double b){
	return a>b?a:b;
}
double sqr(double a){
	return a*a;
}
int main(){
	while(scanf("%lf%lf%lf",&ra,&rb,&l)!=EOF){
		double v1=(pi)*4.0*ra*ra,v2=(pi)*4.0*rb*rb;
		double h1=(ra*ra-rb*rb)/l+l,h2=l-h1/2.0;
		h1/=2.0;
		double s1=(pi)*2.0*ra*(ra-h1),s2=(pi)*2.0*rb*(rb-h2);
		if(l>=(ra+rb)){
			printf("%.13lf",v1+v2);
		}
		else if(fabs(ra-rb)>=l){
			printf("%.13lf",fmax(v1,v2));
			//cout<<fmax(v1,v2)<<endl;
		}
		else{
			printf("%.13lf",v1+v2-s1-s2);
			//cout<<v1+v2-s1-s2<<endl;
		}
	}
	return 0;
}

