#include<bits/stdc++.h>
#define inf 1000000000
#define maxn 1000+5
#define maxm 70000+5
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

struct edge {
    int go, next;
} e[2 * maxm];

struct grou {
    vector<int> a;
};

struct gene {
    int size;
    grou v[maxn];
} P[30], ans_p;

struct rec_point {
    int color, sum;
} conflict_number[maxn];
int nb_CFL;
int tabutable[maxn][maxn];
int head[maxn], tot, m, n, gene_size, color_size;

void insert(int u, int v) {
    e[++tot] = (edge) {v, head[u]};
    head[u] = tot;
    e[++tot] = (edge) {u, head[v]};
    head[v] = tot;
}

void init() {
    n = read();
    m = read();
    //m /= 2;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        insert(u, v);
    }
}

int f(gene p) {
    int ans = 0;
    int color[maxn];
    for (int i = 1; i <= p.size; i++)
        for (int j = 0; j < p.v[i].a.size(); j++) {
            color[p.v[i].a[j]] = i;
        }
    int l = 0, r = 1;
    int q[maxm];
    q[1] = 1;
    int book[maxn];
    memset(book, 0, sizeof(book));
    book[1] = 1;
    while (l != r) {
        int x = q[++l];
        for (int i = head[x], y; i; i = e[i].next) {
            if (color[y = e[i].go] == color[x])
                ans++;
            if (!book[y]) {
                q[++r] = y;
                book[y] = 1;
            }
        }
    }
    return ans / 2;
}

int main(){
	freopen("input.txt", "r", stdin);
	init();
	freopen("output.txt","r",stdin);
	P[1].size=read();
	for(int i=1;i<=P[1].size;i++){
		int n=read();
		for(int j=1;j<=n;j++){
			int x=read();
			P[1].v[i].a.push_back(x);
		}
	}
	cout<<f(P[1])<<endl;
	return 0;
}

