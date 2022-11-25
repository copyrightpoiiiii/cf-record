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
bool check(string s){
    int l = s.length();
    int nnum = 0;
    for(int i=0;i<l;i++)
        if(s[i]=='(')
            nnum++;
        else{
            nnum--;
            if(nnum<0)
                return false;
        }
    return true;
}
void solve(){
    string s;
    cin>>s;
    int n = s.length();
    if(n%2!=0){
        cout<<"NO"<<endl;
        return;
    }
    int num1=0,num2=0;
    for(int i=0;i<n;i++)
        if(s[i]=='(')
            num1++;
        else if(s[i]==')')
            num2++;
    int znum = n/2-num1;
    string s1=s;
    int pos1=0;
    for(int i=0;i<n;i++)
        if(s1[i]=='?'&&znum>0){
            s1[i]='(';
            znum--;
            if(znum==0)
                pos1=i;
        }
        else if(s1[i]=='?'){
            s1[i]=')';
        }
    if(check(s1)){
        string s2=s;
        s2[pos1]=')';
        znum = n/2-num1;
        for(int i=0;i<n;i++)
            if(s2[i]=='?'&&znum>0){
                s2[i]='(';
                znum--;
            }
            else if(s2[i]=='?'){
                s2[i]=')';
            }
        if(check(s2)){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    else{
        cout<<"NO"<<endl;
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