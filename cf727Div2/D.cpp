#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
ll read(){
    ll x=0,f=1;char ch=getchar();
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
/*int n,m,tot,head[maxn];
struct edge{
    int go,next;
}e[maxn*2];
void insert(int u,int v){
    e[++tot].go=v;e[tot].next=head[u];head[u]=tot;
    e[++tot].go=u;e[tot].next=head[v];head[v]=tot;
}*/
struct food{
    ll a,b;
}f[maxn];
bool cmp (food x,food y){
    if(x.b == y.b)
        return x.a < y.a;
    return x.b < y.b;

}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n=read();
    for(int i=1;i<=n;i++){
        f[i].a = read();
        f[i].b = read();
    }
    sort(f+1,f+n+1,cmp);
    ll sum = 0, tot = 0;
    ll l = 1, r = n;
    while(l<=r){
        if(tot >= f[l].b){
            //cout<<f[l].a<<" "<<l<<" "<<r<<" "<<sum<<" "<<tot<<endl;
            sum += f[l].a;
            tot += f[l].a;
            l++;
        }
        else{
            if(f[r].a + tot < f[l].b){
                //cout<<l<<" "<<l<<" "<<r<<" "<<sum<<" "<<tot<<endl;
                sum += f[r].a * 2;
                tot += f[r].a;
                r--;
            }
            else{
                //cout<<l<<" "<<l<<" "<<r<<" "<<sum<<" "<<tot<<endl;
                sum += max(f[l].b-tot,(ll)0)*2;
                f[r].a -= max(f[l].b-tot,(ll)0);
                tot += max(f[l].b-tot,(ll)0);
                if(f[r].a == 0)
                    r--;
            }
        }
    }
    cout<<sum;
    return 0;
}