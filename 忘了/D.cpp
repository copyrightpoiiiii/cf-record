#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <map>
using namespace std;
#define LL long long
#define fi first
#define se second

const LL MAXV=200000+3;
const int MAXE=200000+3;

struct HashMap
{
    const static int mod=20011;
    const static int maxn=500003;
    int head[mod];//?????
    int next[maxn];//?????????
    int size;//?????
    int u[maxn], v[maxn] ,val[maxn];//?,?
    void clear()
    {
        size=0;
        memset(head,-1,sizeof head);
    }
    inline void insert(int _u,int _v, int _val)
    {
        if(_u>_v)
            swap(_u, _v);
        int p=(_u*MAXV+_v)%mod;//???????
        u[size]=_u;
        v[size]=_v;
        val[size]=_val;
        next[size]=head[p];
        head[p]=size++;
    }
    int find(int _u, int _v)
    {
        if(_u>_v)
            swap(_u, _v);
        int p=(_u*MAXV+_v)%mod;
        for(int i=head[p];~i;i=next[i])//????????
            if(u[i]==_u && v[i]==_v)
                return val[i];
        return -1;//???
    }
}hm;

struct Edge
{
    int from, to, next;
}edge[2*MAXE];

int V, E, deg[MAXV], cnt[MAXE];
int head[MAXV];
int save[MAXV], save_id[MAXV];

void init()//???
{
    hm.clear();
    for(int i=1;i<=V;++i)
    {
        deg[i]=0;
        head[i]=-1;
    }
    for(int i=0;i<E;++i)
        cnt[i]=0;
    save[0]=0;
}

int main()
{
    scanf("%d%d", &V, &E);
        init();
        for(int i=0;i<E;++i)
        {
            int id=i<<1;
            int u, v;
            scanf("%d%d", &u, &v);
            hm.insert(u, v, i);
            edge[id].from=u;
            edge[id].to=v;
            edge[id].next=head[u];
            head[u]=id;
            id|=1;
            edge[id].from=v;
            edge[id].to=u;
            edge[id].next=head[v];
            head[v]=id;
            ++deg[u];
            ++deg[v];
        }
        for(int u=1;u<=V;++u)
        {
            save[0]=0;
            for(int i=head[u];~i;i=edge[i].next)
            {
                int v=edge[i].to;
                if(deg[u]<deg[v] || (deg[u]==deg[v] && u<v))//??????????
                {
                    save[++save[0]]=v;
                    save_id[save[0]]=i;
                }
            }
            for(int i=1;i<=save[0];++i)
                for(int j=1;j<i;++j)
                {
                    int id=hm.find(save[i], save[j]);
                    if(~id)//?????,?????????
                    {
                        ++cnt[id];
                        ++cnt[save_id[i]>>1];
                        ++cnt[save_id[j]>>1];
                    }
                }
        }
        LL ans=0;
        for(int i=0;i<E;++i)
            ans+=cnt[i]*(cnt[i]-1ll)/2ll;
        printf("%lld\n", ans);

    return 0;
}
