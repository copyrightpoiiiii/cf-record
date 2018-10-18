#include<iostream>
#include<sstream>
#include<cstring>
#include<string>
#include<cstdio>
#include<vector>
#include<algorithm>
#define LL unsigned long long
using namespace std;
const int maxn=101;
int cnt1[maxn],isp,sp[maxn];          //cnt1[i]--?i???????,isp--????????????‘/’,sp[i]--?i?????????‘/’
string str[maxn],str1[maxn],str2;     //str[i]--?i?????????,str1[i]--?i?????,str2--???????????
string sp1[maxn][maxn],sp2[maxn];     //sp1[i]--???i????????,sp2--???????????????
string is_num(string s){              //??????????:?--????0?????;??--??“-”
    LL res=0,ok=0;
    string ss="";
    int len=s.length();
    for(int i=0;i<len;i++){
        if(s[i]<'0'||s[i]>'9')return "-";
        if(ok||s[i]!='0')ss+=s[i],ok=1;
    }
    if(ss=="")ss="0";
    return ss;
}
void getinfo(string s,string s1[],int &f,int &t){       //??????????????,???????‘/’
    f=t=0; 
    int len=s.length();
    if(s[len-1]=='/')f=1;
    for(int p=0;p<len;p++){
        if(s[p]=='/')s[p]=' ';
    }
    string ss;
    stringstream in(s);
    while(in>>ss)s1[t++]=ss;
}
bool match(int t,int j,string &s){                      //??????????j????????
    s="";
    int p1=0,p2=0;
    while(p1<t&&p2<cnt1[j]){
        if(sp2[p1]==sp1[j][p2]);
        else if(sp1[j][p2]=="<int>"){
            string f=is_num(sp2[p1]);
            if(f=="-"){return 0;}
            s+=" "+f;
        }
        else if(sp1[j][p2]=="<str>"){s+=" "+sp2[p1];}
        else if(sp1[j][p2]=="<path>"){                 //<path>??????
            s+=" "+sp2[p1++];
            while(p1<t)s+="/"+sp2[p1++];
            if(isp)s+='/';
            return 1;
        }
        else return 0;
        p1++;p2++;
    }
    if(isp^sp[j])return 0;                            //????--???‘/’????‘/’????
    if(p1!=t||p2!=cnt1[j])return 0;                   //????
    return 1;
}
int main(){                                           //???
    //freopen("in.txt","r",stdin);
    int n,m;
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>str1[i]>>str[i];
        getinfo(str1[i],sp1[i],sp[i],cnt1[i]);
    }
    for(int i=0;i<m;i++){
        string ans;
        int cnt=0;isp=0;
        cin>>str2;
        getinfo(str2,sp2,isp,cnt);
        bool ok=0;
        for(int j=0;j<n;j++){
            if(match(cnt,j,ans)){
                cout<<str[j]<<ans<<endl;;
                ok=1;break;
            }
        }
        if(!ok)cout<<404<<endl;
    }
    return 0;
}

