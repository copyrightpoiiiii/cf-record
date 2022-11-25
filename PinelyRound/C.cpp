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
int ind[105];
void solve(){
    int n=read();
    set<int> ans[105];
    memset(ind, 0, sizeof(ind));
    vector<int> edge[105];
    for(int i=1;i<=n;i++){
        string s;
        cin>>s;
        for(int j=0;j<n;j++)
            if(s[j]=='1'){
                edge[i].push_back(j+1);
                ind[j+1]++;
            }
    }
    int now=1;
    queue<int> q;
    for(int i=1;i<=n;i++)
        if(ind[i]==0){
            q.push(i);
        }
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ans[x].insert(now);
        now++;
        for(auto e:edge[x]){
            ind[e]--;
            for(auto y:ans[x])
                ans[e].insert(y);
            if(ind[e]==0)
                q.push(e);
        }
    }
    for(int i=1;i<=n;i++){
        cout<<ans[i].size();
        for(auto y:ans[i])
            cout<<" "<<y;
        cout<<endl;
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