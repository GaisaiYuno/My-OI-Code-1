#include<bits/stdc++.h>
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
#define x first
#define y second
using namespace std;
typedef long long LL;
typedef pair<int, int> PII;
const int MX = 305;
const LL mod = 1e9 + 7;
LL dp[MX][MX], f[MX], invf[MX];
LL pow(LL a, LL b) {
    LL ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}
void init() {
    f[0] = 1;
    for (int i = 1; i < MX; i++) f[i] = f[i - 1] * i % mod;
    invf[MX - 1] = pow(f[MX - 1], mod - 2);
    for (int i = MX - 2; i >= 0; i--) invf[i] = invf[i + 1] * (i + 1) % mod;
}
LL C(int n, int m) {
    if (n < 0 || m < 0 || m > n) return 0;
    if (m == 0 || m == n)  return 1;
    return f[n] * invf[n - m] % mod * invf[m] % mod;
}
bool check(LL x) {
    LL l = 1, r = 1e9;
    while (l <= r) {
        LL m = (l + r) >> 1;
        if (m * m == x) return 1;
        if (m * m < x) l = m + 1;
        else r = m - 1;
    }
    return 0;
}
LL a[305];
int sz, cnt[MX], vis[MX];
int main() {
    init();
    int n;
    //freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for (int i = 1; i <= n; i++) {
        if (vis[i]) continue;
        sz++;
        for (int j = i; j <= n; j++) {
            if (check(a[i]*a[j])) vis[j] = 1, cnt[sz]++;
        }
    }
    int m = cnt[1] - 1;
    dp[1][m] = 1;
    for (int i = 2; i <= sz; m += cnt[i++]) {
        for (int j = 0; j <= m; j++) {//dp[i-1][j]
            if (dp[i - 1][j] == 0) continue;
            for (int k = 0; k < cnt[i]; k++) {//分成k+1组，有a[i]-1-k个间隙
                for (int p = 0; p <= min(k + 1, j); p++) { //插入p个间隙中
                    LL tmp = dp[i - 1][j] * C(cnt[i] - 1, k) % mod * C(j, p) % mod * C(m + 2 - j, k + 1 - p) % mod;
                    (dp[i][j + cnt[i] - 1 - k - p] += tmp) %= mod;
                }
            }
        }
    }
    LL ans = dp[sz][0];
    for (int i = 1; i <= sz; i++) ans = ans * f[cnt[i]] % mod;
    printf("%I64d\n", ans);
    return 0;
}

