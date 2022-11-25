#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 100000+5
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
int read(){
    int x=0,f=1;char ch=getchar();
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
/*
void insert(int u,int v,int w){
	 e[++tot].go=v;e[tot].next=head[u];e[tot].w=w;head[u]=tot;
	 e[++tot].go=u;e[tot].next=head[v];e[tot].w=w;head[v]=tot;
}
*/
struct ur{
	string x,y;
}a[105];
int n,m;
string getnext(string s,int l){
	int st=l;
	for(;s[l]!='/'&&l<s.length();l++);
	return s.substr(st,max(0,l-st));
}
bool judge(char ch){
	if(ch>='0'&&ch<='9')
		return 1;
	else if(ch>='a'&&ch<='z')return 1;
	else if(ch>='A'&&ch<='Z')return 1;
	else if(ch=='/'||ch=='-'||ch=='_'||ch=='.')return 1;
	else return 0;
}
int main(){	
	n=read();m=read();
	for1(i,n)
		cin>>a[i].x>>a[i].y;
	while(m--){
		string tmp;
		cin>>tmp;
		bool v=true;
		for(int i=0;i<tmp.length();i++)
			if(!judge(tmp[i])){
				cout<<"404"<<endl;
				v=false;
				break;
			}
		if(!v)continue;
		string na,nb;
		int i,ju=0;
		for(i=1;i<tmp.length();i++)
			if(tmp[i]=='/'){
				na=tmp.substr(1,i-1);	
				i++;
				break;
			}
			else if(i==tmp.length()-1){
				na=tmp.substr(1,i);
				break;
			}
		for(int j=1;j<=n;j++){
			int k;
			string ans=a[j].y;
			for(k=1;k<a[j].x.length();k++)
				if(a[j].x[k]=='/'){
					nb=a[j].x.substr(1,k-1);
					k++;
					break;
				}
				else if(k==a[j].x.length()-1){
					nb=a[j].x.substr(1,k);
					break;
				}
			cout<<na<<" sss "<<nb<<endl;
			if(na!=nb)
				continue;
			bool flag=true;
			if(tmp==a[j].x){
				cout<<a[j].y<<endl;
				break;
			}
			while(1){
				if(a[j].x[k]=='<'){
					k++;
					if(a[j].x[k]=='i'){
						ans+=' ';
						//cout<<i<<endl;
						bool f=false,ji=false;
						while(tmp[i]!='/'&&i<tmp.length()){
							if(tmp[i]<'0'||tmp[i]>'9'){
								//cout<<tmp[i]<<endl;
								f=false;
								flag=false;
								break;
							}
							if(tmp[i]=='0'&&f){
								ans+=tmp[i];
								ji=true;
							}
							else if(tmp[i]!='0'){
								f=true;
								ji=true;
								ans+=tmp[i];
							}
							i++;
						}
						if(!ji)
							flag=false;
						if(!f)
							ans+='0';
						cout<<i<<endl;
						cout<<tmp[i+1]<<" "<<a[j].x[k+4]<<endl;
						if(tmp[i+1]!=a[j].x[k+4])
							flag=false;
						//ans+=' ';
						//cout<<ans<<endl;
						if(!flag)break;
						i++;
						k+=5;
					}
					else if(a[j].x[k]=='s'){
						if(i>=tmp.length()-1){flag=false;break;}
						ans+=' '+getnext(tmp,i);
						for(;tmp[i]!='/'&&i<tmp.length();i++);
						cout<<i+1<<endl;
						cout<<tmp[i+1]<<" "<<a[j].x[k+4]<<endl;
						if(tmp[i+1]!=a[j].x[k+4]){
							flag=false;
							break;
						}
						i++;
						k+=5;
					}
					else{
						if(i>=tmp.length()||tmp[i]=='/')flag=false;
						ans+=' '+tmp.substr(i,tmp.length()-i);
						break;
					}
				}
				else{
					cout<<"ss"<<endl;
					nb=getnext(a[j].x,k);
					string tmp2=getnext(tmp,i);
					if(tmp2!=nb){
						flag=false;
						break;
					}
					ans+=' '+tmp2;
					for(;tmp[i]!='/'&&i<tmp.length()-1;i++);
					for(;a[j].x[k]!='/'&&k<a[j].x.length()-1;k++);
					cout<<tmp[i]<<" "<<a[j].x[k]<<endl;
					cout<<i<<" "<<k<<endl;
						if(tmp[i]!=a[j].x[k]){
							flag=false;
							break;
						}
					k++;i++;
				}
				if((i>=tmp.length())&&(k>=a[j].x.length()))
					break;
				//cout<<i<<" "<<k<<endl;
				if((i>=tmp.length())||(k>=a[j].x.length())){
					flag=false;
					break;
				}
			}
			i=na.length()+2;
			if(flag){
				ju=1;
				cout<<ans<<endl;
				/*while(i<tmp.length()){
					string t=getnext(tmp,i);
					cout<<t<<" ";
					for(;tmp[i]!='/'&&i<tmp.length();i++);
					i++;
				}*/
				//cout<<endl;
				break;
			}
			else {flag=true;continue;}
		}
		if(!ju)
			cout<<"404\n";
	}
	return 0;
}

