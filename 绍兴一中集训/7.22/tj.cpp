#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <assert.h>
using namespace std;
#define MAXN 100010
struct arr {
    int cnt[MAXN << 1];
    inline int & operator [] (const int index) { return cnt[index + MAXN]; }
} A, B, rec;
int n, head[MAXN], nxt[MAXN << 1], to[MAXN << 1], val[MAXN << 1], tot;
void addedge(int b, int e, int v) {
    nxt[++tot] = head[b]; head[b] = tot; to[tot] = e; val[tot] = v;
    nxt[++tot] = head[e]; head[e] = tot; to[tot] = b; val[tot] = v;
}
int sz[MAXN], sznow, rt, rtv;
bool vis[MAXN];
void getroot(int u, int fa) {
    int maxn = 0;
    sz[u] = 1;
    for (int i = head[u]; i; i = nxt[i])
        if (!vis[to[i]] && to[i] != fa) {
            getroot(to[i], u);
            sz[u] += sz[to[i]];
            maxn = max(maxn, sz[to[i]]);
        }
    maxn = max(maxn, sznow - sz[u]);
    if (maxn < rtv) rtv = maxn, rt = u;
}
int liA[MAXN], liB[MAXN], baka, bakb, tcnt;
void dfs(int u, int fa, int v) {
    if (rec[v]) {
        tcnt += v == 0 && rec[v] == 1;
        ++B[v], liB[++bakb] = v;
    } else ++A[v], liA[++baka] = v;
    ++rec[v];
    for (int i = head[u]; i; i = nxt[i])
        if (to[i] != fa && !vis[to[i]])
            dfs(to[i], u, v + val[i]);
    --rec[v];
}
long long calc(int u, int v) {
    tcnt = baka = bakb = 0;
    if (v) liA[++baka] = 0, ++rec[0];
    dfs(u, 0, v);
    if (v) --rec[0];
    long long resA = !v ? -tcnt : 0, resB = 0;
    for (int i = 1; i <= bakb; ++i) {
        resA += A[-liB[i]];
        resB += B[-liB[i]];
        if (liB[i] == 0) --resB;
    }
    resB >>= 1;
    for (int i = 1; i <= baka; ++i) A[liA[i]] = 0;
    for (int i = 1; i <= bakb; ++i) B[liB[i]] = 0;
    return resA + resB;
}
long long ans;
void solve(int u) {
    vis[u] = true;
    ans += calc(u, 0);
    for (int i = head[u]; i; i = nxt[i])
        if (!vis[to[i]]){
            ans -= calc(to[i], val[i]);
            rtv = 0x3f3f3f3f; sznow = sz[to[i]];
            getroot(to[i], 0);
            solve(rt);
        }
}
int t1, t2, t3;
int main() {
    scanf("%d", &n);
    for (int i = 1; i != n; ++i) {
        scanf("%d%d%d", &t1, &t2, &t3);
        addedge(t1, t2, t3 == 1 ? 1 : - 1);
    }
    rtv = 0x3f3f3f3f; sznow = n;
    getroot(1, 0); solve(rt);
    printf("%lld\n", ans);
    return 0;
}
