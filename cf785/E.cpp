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
pair<int,int> a[2000];
int mp[2000][2000];
int tot = 0;
int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n ,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)
        for(int j = 1;j<=n;j++)
            tot++;
            //a[tot++] = make_pair(i,j);
    int sum = 0;
    for(int i=0;i<tot;i++)
        for(int j=i+1;j<tot;j++){
            mp[i][j] = i^j;
            sum += mp[i][j];
        }
    cout<<sum<<endl;
    for(int i=1;i<=n;i++){
        for(int j=0;j<n-1;j++){
            int x = (i-1)*n+j,y=(i-1)*n+j+1;
            if(j==0)
                cout<<mp[x][y];
            else
                cout<<" "<<mp[x][y];
            cout.flush();
        }
        cout<<endl;
        cout.flush();
    }
    for(int j=1;j<n;j++){
        for(int i=0;i<n;i++){
            int x = (j-1)*n+i,y=(j)*n+i;
            if(i==0)
                cout<<mp[x][y];
            else
                cout<<" "<<mp[x][y];
            cout.flush();
        }
        cout<<endl;
        cout.flush();
    }
    int now=0;
    while(k--){
        cout.flush();
        int tmp ;
        cin>>tmp;
        now^=tmp;
        int row = now/n + 1,col=now%n + 1;
        cout<<row<<" "<<col<<endl;
        cout.flush();
    }
    return 0;
}