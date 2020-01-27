#include <algorithm>
#include <cstdio>
#include <cstring>

using std::min;

const int K = 9, N = 1 << K;
int a[N + 1][N + 1], f[N][N + 1], s, n;

int dfs(int k, int num) { 
    if (k == n) return 0;
    if (~f[k][num]) return f[k][num];
    int tmp = 0, tmpk = 2;
    while (tmp < s && !(tmpk & 1)) {
        ++tmp;
        tmpk >>= 1;
    }
    printf("%d\n",tmp);
    int ss = 1 << tmp, ne = (num ^ ss) >> tmp << tmp;
    f[k][num] = 1E9;
    for (int i = 0; i < ss; ++i)
        f[k][num] = min(f[k][num], a[num][ne + i] + dfs(k + 1, ne + i));
    return f[k][num];
}

int main() {
//    freopen("alb.in", "r", stdin);
//    freopen("alb.out", "w", stdout);
    scanf("%d", &s);
    n = 1 << s;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) scanf("%d", &a[i][j]);
    memset(f, -1, sizeof f);
    printf("%d", dfs(0, n));
    return 0;
}
