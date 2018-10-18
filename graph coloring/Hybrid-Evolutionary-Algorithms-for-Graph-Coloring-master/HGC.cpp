#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <vector>
#include <queue>
#include <ctime>
#include <cmath>

#define maxn 500+5
#define maxm 40000+5
#define init_size 20
#define L_LS 2000
#define L_check 400
#define E  2.7182818285
#define A 10
#define arf 0.6
using namespace std;

struct edge {
    int go, next;
} e[2 * maxm];

struct grou {
    vector<int> a;
};

struct gene {
    int size;
    grou v[maxn];
} P[maxn], ans_p;

struct conflict_point {
    int id, pri, num;
} rec_point[maxn];

int tabutable[maxn][maxn];
int point_pos[maxn];
int rec_point_size;
int head[maxn], tot, m, n, gene_size, color_size;

int read() {
    int x = 0, f = 1;
    char ch = getchar();
    while (ch < '0' || ch > '9') {
        if (ch == '-')f = -1;
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9') {
        x = x * 10 + ch - '0';
        ch = getchar();
    }
    return x * f;
}

void insert(int u, int v) {
    e[++tot] = (edge) {v, head[u]};
    head[u] = tot;
    e[++tot] = (edge) {u, head[v]};
    head[v] = tot;
}

void init() {
    n = read();
    m = read();
    m /= 2;
    for (int i = 1; i <= m; i++) {
        int u = read(), v = read();
        insert(u, v);
    }
}

void init_gen(int lim, const int size) {
    for (int i = 1; i <= gene_size; i++) {
        for (int j = 1; j <= P[i].size; j++)
            P[i].v[j].a.clear();
    }
    bool vis[maxn], vispoint[maxn];
    gene_size = size;
    for (int i = 1; i <= size; i++) {
        memset(vis, 0, sizeof(vis));
        P[i].size = 0;
        for (int j = 1; j <= n; j++) {
            int x = rand() % n + 1;
            while (vis[x]) {
                x = rand() % n + 1;
            }
            memset(vispoint, 0, sizeof(vispoint));
            for (int k = head[x], y; k; k = e[k].next) {
                y = e[k].go;
                vispoint[y] = 1;
            }
            int flag = 0;
            for (int k = 1; k <= P[i].size; k++) {
                int flaggro = 0;
                for (int t = 0; t < P[i].v[k].a.size(); t++) {
                    if (vispoint[P[i].v[k].a[t]]) {
                        flaggro = 1;
                        break;
                    }
                }
                if (!flaggro) {
                    P[i].v[k].a.push_back(x);
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                if (P[i].size < lim) {
                    P[i].size++;
                    P[i].v[P[i].size].a.push_back(x);
                } else {
                    int to_pri = rand() % lim + 1;
                    P[i].v[to_pri].a.push_back(x);
                }
            }
            vis[x] = 1;
        }
    }
}

void crossover(gene s1, gene s2, gene &s) {
    int book[maxn], book_point[maxn];
    memset(book_point, 0, sizeof(book_point));
    s.size = s1.size;
    for (int i = 1; i <= s1.size; i++) {
        memset(book, 0, sizeof(book));
        int maxnum = 0, maxid;
        if (i % 2 == 1) {
            for (int j = 1; j <= s1.size; j++)
                if (s1.v[j].a.size() > maxnum) {
                    maxnum = s1.v[j].a.size();
                    maxid = j;
                }
            s.v[i].a.swap(s1.v[maxid].a);
            for (int j = 0; j < s.v[i].a.size(); j++) {
                book[s.v[i].a[j]] = 1;
                book_point[s.v[i].a[j]] = 1;
            }
            gene news2;
            for (int j = 1; j <= s2.size; j++) {
                for (int k = 0, y; k < s2.v[j].a.size(); k++)
                    if (!book[y = s2.v[j].a[k]])
                        news2.v[j].a.push_back(y);
                s2.v[j].a.swap(news2.v[j].a);
            }
        } else {
            for (int j = 1; j <= s2.size; j++)
                if (s2.v[j].a.size() > maxnum) {
                    maxnum = s2.v[j].a.size();
                    maxid = j;
                }
            s.v[i].a.swap(s2.v[maxid].a);
            for (int j = 0; j < s.v[i].a.size(); j++) {
                book[s.v[i].a[j]] = 1;
                book_point[s.v[i].a[j]] = 1;
            }
            gene news1;
            for (int j = 1; j <= s1.size; j++) {
                for (int k = 0, y; k < s1.v[j].a.size(); k++)
                    if (!book[y = s1.v[j].a[k]])
                        news1.v[j].a.push_back(y);
                s1.v[j].a.swap(news1.v[j].a);
            }
        }
    }
    for (int i = 1; i <= n; i++)
        if (!book_point[i]) {
            int x = rand() % s.size + 1;
            s.v[x].a.push_back(i);
        }
}

bool judge(gene p) {
    int color[maxn];
    for (int i = 1; i <= p.size; i++)
        for (int j = 0; j < p.v[i].a.size(); j++)
            color[p.v[i].a[j]] = i;
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
                return 0;
            if (!book[y]) {
                q[++r] = y;
                book[y] = 1;
            }
        }
    }
    return 1;
}

int f(gene p) {
    int ans = 0;
    int color[maxn];
    for (int i = 1; i <= p.size; i++)
        for (int j = 0; j < p.v[i].a.size(); j++) {
            color[p.v[i].a[j]] = i;
            point_pos[p.v[i].a[j]] = j;
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

void find(gene p) {
    memset(rec_point, 0, sizeof(rec_point));
    rec_point_size = 0;
    int color[maxn], rec[maxn];
    memset(rec, 0, sizeof(rec));
    for (int i = 1; i <= p.size; i++)
        for (int j = 0; j < p.v[i].a.size(); j++)
            color[p.v[i].a[j]] = i;
    int l = 0, r = 1;
    int q[maxm];
    q[1] = 1;
    int book[maxn];
    memset(book, 0, sizeof(book));
    book[1] = 1;
    while (l != r) {
        int x = q[++l];
        for (int i = head[x], y; i; i = e[i].next) {
            if (color[y = e[i].go] == color[x] && (!rec[x])) {
                rec_point[++rec_point_size].id = x;
                rec_point[rec_point_size].pri = color[x];
                rec[x] = 1;
            }
            if (!book[y]) {
                q[++r] = y;
                book[y] = 1;
            }
        }
    }
}

int solve_CFL(gene p) {
    int rec[maxn];
    int color[maxn];
    for (int i = 1; i <= p.size; i++)
        for (int j = 0; j < p.v[i].a.size(); j++)
            color[p.v[i].a[j]] = i;
    int l = 0, r = 1;
    int q[maxm];
    q[1] = 1;
    int book[maxn];
    memset(book, 0, sizeof(book));
    book[1] = 1;
    while (l != r) {
        int x = q[++l];
        for (int i = head[x], y; i; i = e[i].next) {
            if (color[y = e[i].go] == color[x]) {
                rec[x] = 1;
            }
            if (!book[y]) {
                q[++r] = y;
                book[y] = 1;
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
        if (rec[i])
            sum++;
    return sum;
}

void localSearch(gene &p, int iter) {
    gene best_res = p;
    int best_fun = f(p);
    memset(tabutable, 0x3f, sizeof(tabutable));
    while (iter--) {
        int tl, v = 1, nb = solve_CFL(p), new_pri = -1, new_pri_f,rec_id=0;
        tl = rand() % A + arf * nb;
        find(p);
        if (!rec_point_size)return;
        while (v <= rec_point_size) {
            new_pri_f = n*2;
            for (int i = 0; i < p.v[rec_point[v].pri].a.size(); i++)
                if (p.v[rec_point[v].pri].a[i] == rec_point[v].id)
                    p.v[rec_point[v].pri].a.erase(p.v[rec_point[v].pri].a.begin() + i);
            int rec_new_color[maxn];
            memset(rec_new_color,0, sizeof(rec_new_color));
            for (int i = 1; i <= p.size; i++)
                if (i != rec_point[v].pri && (tabutable[rec_point[v].id][i] >= iter)) {
                    int rec_conflict = 0;
                    for (int j = 0; j < p.v[i].a.size(); j++)
                        rec_new_color[p.v[i].a[j]] = i;
                    for (int j = head[rec_point[v].id]; j; j = e[j].next)
                        if (rec_new_color[e[j].go] == i)
                            rec_conflict++;
                    if (rec_conflict < new_pri_f) {
                        new_pri = i;
                        rec_id=v;
                        new_pri_f = rec_conflict;
                    }
                }
            if(new_pri!=-1) {
                gene tmp_gene = p;
                tmp_gene.v[new_pri].a.push_back(rec_point[v].id);
                if(f(tmp_gene)>best_fun)
                    new_pri=-1;
            }
            if(new_pri==-1) {
                p.v[rec_point[v].pri].a.push_back(rec_point[v].id);
                v++;
            }
            else break;
        }
        if (new_pri == -1) {
            p = best_res;
            return;
        }
        p.v[new_pri].a.push_back(rec_point[rec_id].id);
        int tmp_answer = f(p);
        if (tmp_answer <= best_fun) {
            best_res = p;
            best_fun = tmp_answer;
        }
        tabutable[rec_point[rec_id].id][rec_point[rec_id].pri] = iter - tl;
        if (judge(p))
            return;
    }
    p = best_res;
}

int dis(gene s, gene t) {
    int color[maxn];
    int sum = 0;
    for (int i = 1; i <= t.size; i++)
        for (int j = 0; j < t.v[i].a.size(); j++)
            color[t.v[i].a[j]] = i;
    for (int i = 1; i <= s.size; i++) {
        int rec_num[maxn], max_rec = 0;
        memset(rec_num, 0, sizeof(rec_num));
        for (int j = 0; j < s.v[i].a.size(); j++) {
            rec_num[color[s.v[i].a[j]]]++;
            max_rec = max(max_rec, rec_num[color[s.v[i].a[j]]]);
        }
        sum += max_rec;
    }
    return n - sum;
}

void optimize() {
    long double s_gene[gene_size + 5];
    for (int i = 1; i <= gene_size; i++)
        s_gene[i] = f(P[i]);
    int min_dis[maxn];
    memset(min_dis, 0x3f, sizeof(min_dis));
    for (int i = 1; i <= gene_size; i++)
        for (int j = 1; j <= gene_size; j++)
            if (i != j) {
                min_dis[i] = min(min_dis[i], min(dis(P[i], P[j]), dis(P[j], P[i])));
            }
    long double max_index = 0;
    int max_id = gene_size;
    for (int i = 1; i <= gene_size; i++) {
        s_gene[i] += pow(E, (long double) 0.08 * n * (long double) n / min_dis[i]);
        if (s_gene[i] > max_index) {
            max_index = s_gene[i];
            max_id = i;
        }
    }
    P[max_id] = P[gene_size];
    gene_size--;
}

bool check(int x) {
    int stop_cond = L_check;
    for (int i = 1; i <= init_size; i++)
        if (judge(P[i])) {
            ans_p = P[i];
            return 1;
        }
    while (stop_cond--) {
        int p1 = rand() % init_size + 1, p2 = rand() % init_size + 1;
        gene ps;
        crossover(P[p1], P[p2], ps);
        localSearch(ps, L_LS);
        if (judge(ps)) {
            ans_p = ps;
            return 1;
        }
        P[++gene_size] = ps;
        optimize();
    }
    return 0;
}

void output_gene(gene p) {
    cout << p.size << endl;
    for (int i = 1; i <= p.size; i++) {
        for (int j = 0; j < p.v[i].a.size(); j++)
            cout << p.v[i].a[j] << " ";
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    srand((unsigned) time(NULL));
    init();
    int l = 1, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        color_size = mid;
        init_gen(mid, init_size);
        if (check(mid))r = mid - 1;
        else l = mid + 1;
    }
    output_gene(ans_p);
    return 0;
}
