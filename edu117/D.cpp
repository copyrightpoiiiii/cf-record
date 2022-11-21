#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define maxn (300000+5)
#define mod 1000000007
int read(){
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=10*x+ch-'0';ch=getchar();}
    return x*f;
}
ll readll(){
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
int a[1005];
struct qq{
    int id,va;
}aa[1005];
int ans[1005];
vector<pair<int,int> > test;
bool cmp(qq x,qq y){
    if(x.va<=y.va)
        return true;
    return false;
}
void solve(){
    int n=read();
    memset(a,0,sizeof(a));
    memset(ans,0,sizeof(ans));
    test.clear();
    for(int i=1;i<=n;i++){
        int l =read(),r=read();
        a[l]++;
        a[r+1]+=-1;
    }
    int sum = 0;
    for(int i = 1;i<=n;i++){
        sum+=a[i];
        aa[i].id=i;
        aa[i].va=sum;
    }
    sort(aa+1,aa+n+1,cmp);
    test.push_back(make_pair(1,n));
    for(int i=1;i<=n;i++){
        for(int j=0;j<test.size();j++){
            pair<int,int> tmp = test[j];
            if(aa[i].id>=tmp.first&&aa[i].id<=tmp.second){
                cout<<tmp.first<<" "<<aa[i].id<<" "<<tmp.second<<endl;
                test.erase(test.begin()+j);
                pair<int,int> aaa=make_pair(tmp.first,aa[i].id-1);
                pair<int,int> bbb=make_pair(aa[i].id+1,tmp.second);
                if(aaa.first<=aaa.second){
                    test.push_back(aaa);
                }
                if(bbb.first<=bbb.second){
                    test.push_back(bbb);
                }
                cout<<tmp.first<<" "<<tmp.second<<" "<<aa[i].id<<endl;
                break;
            }
        }
    }
    
}
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int T = read();
    while(T--){
        solve();
    }
    return 0;
}