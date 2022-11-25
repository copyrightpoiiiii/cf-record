#include <bits/stdc++.h>
using namespace std;
#define dbg(x) cout << #x << " = " << x << endl;

typedef long long ll;
typedef unsigned long long ull;

const int maxn = 1e4 + 5;
const int mod = 1e9 + 7;
const int inf = 1 << 30;
const double eps = 1e-6;

int n, m, k;

int a[maxn];
int cnt[maxn];

int main() {
		freopen("input.in","r",stdin);
	freopen("ou.out","w",stdout);
  scanf("%d", &m);
  while (m--) {
    scanf("%d", &n);
    memset(a, 0, sizeof(a));
    memset(cnt, 0, sizeof(cnt));
    int x;
    int r = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &x);
      r = max(r, x);
      a[x]++;
    }
    bool flag = 0;
    double min_gap = r + 1;
    int last = 0;
    int ans1 = 0, ans2 = 0;
    for (int i = r; i >= 0; i--) {
      if (a[i] >= 2) {
        cnt[i]++;
        if (cnt[last]) {
          if (min_gap > double(last) / double(i)) {
            min_gap = double(last) / double(i);
            ans1 = i;
            ans2 = last;
          }
        }
        last = i;
      }
      if (a[i] >= 4) {
        ans1 = i;
        flag = 1;
        break;
      }
    }
    if (flag) {
      printf("%d %d %d %d\n", ans1, ans1, ans1, ans1);
    } else {
      printf("%d %d %d %d\n", ans1, ans1, ans2, ans2);
    }
  }
  return 0;
}
