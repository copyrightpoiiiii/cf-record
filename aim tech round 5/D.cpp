#include<bits/stdc++.h>
#define inf 408983066
#define maxn (400000+5)
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
ll read(){
    ll x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
int n,m,tot,l[maxm],r[maxm],s[maxm],rnd[maxm];
ll w[maxm],v[maxm];
int root;
struct rec{int l,r,rt;}t[4*maxn];
inline void pushup(int k)
{s[k]=s[l[k]]+s[r[k]]+w[k];}
inline void rturn(int &k)
{int t=l[k];l[k]=r[t];r[t]=k;s[t]=s[k];pushup(k);k=t;}
inline void lturn(int &k)
{int t=r[k];r[k]=l[t];l[t]=k;s[t]=s[k];pushup(k);k=t;}
void ins(int &k,ll num)
{
    if(!k)
    {k=++tot;v[k]=num;s[k]=w[k]=1;l[k]=r[k]=0;rnd[k]=rand();return;}
    s[k]++;
    if(v[k]==num)w[k]++;
    else if(num<v[k])
      {ins(l[k],num);if(rnd[l[k]]<rnd[k])rturn(k);}
    else
      {ins(r[k],num);if(rnd[r[k]]<rnd[k])lturn(k);}  
}
void del(int &k,int num)
{
    if(v[k]==num)
    {
        if(w[k]>1){w[k]--;s[k]--;}
        else if(l[k]*r[k]==0)k=l[k]+r[k];
        else if(rnd[l[k]]<rnd[r[k]])
         {rturn(k);del(k,num);}
        else {lturn(k);del(k,num);} 
        return;
    }
    s[k]--;
    if(num<v[k])del(l[k],num);else del(r[k],num);
}
ll pre(int k,ll num)
{
    if(!k)return -inf;
    if(num<=v[k])return pre(l[k],num);
    else 
    {
        int t=pre(r[k],num);
        return t==-inf?v[k]:t;
    }
}
ll suc(int k,ll num)
{
    if(!k)return inf;
    if(num>=v[k])return suc(r[k],num);
    else
    {
        int t=suc(l[k],num);
        return t==inf?v[k]:t;
    }
}
ll qpow(ll x){
	if(x==0)return 1;
	else{
		ll tmp=qpow(x/2);
			tmp%=mod;
		if(x%2==1){
			
			return (((tmp*tmp)%mod)*2)%mod;
		}
		else{
			return ((tmp*tmp)%mod);
		}
	}
}
ll la_qi=0,la_ho=408983066;
int main(){
	n=read();
	ll ans=1,last=-1;
	ll cnt=0;
	for(int i=1;i<=n;i++){
		char ch=getchar();
		while(ch!='D'&&ch!='C')ch=getchar();
		ll tmp=read();
		if(ch=='D'){
			ins(root,tmp);
			if(tmp>la_qi&&tmp<la_ho)
				cnt++;
		}
		else{
			if(last>0){
				ll qi=la_qi,ho=la_ho;
				if(qi<=tmp&&ho>=tmp){
					if(tmp==la_qi||tmp==la_ho){
						last=tmp;
					}
					else {
						ans=(ans*2)%mod;
						last=tmp;
					}
				}
				else{
					cout<<0<<endl;
					return 0;
				}
			}
			else{
				ans=(ans*2)%mod;
				last=tmp;
			}
			la_qi=pre(root,tmp);la_ho=suc(root,tmp);
			del(root,tmp);
			cnt=0;
		}
	}
	//cnt%=mod;
	ans=(ans*(cnt+1))%mod;
	cout<<ans%mod<<endl;
	return 0;
}

