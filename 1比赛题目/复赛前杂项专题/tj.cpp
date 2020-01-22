#include <bits/stdc++.h>
#define int long long
#define N 50010
using namespace std;
template <typename node> void read(node &x) {
    x = 0; int f = 1; char c = getchar();
    while (!isdigit(c)) {if (c == '-') f = -1; c = getchar();}
    while (isdigit(c)) x = x * 10 + c - '0', c = getchar(); x *= f;
}
int a[N], b[N], f[N], g[N], s1[N], s2[N], st[N];
vector <int> v[N];
int solve1(int n) {
    for (int i = 1; i <= n; i++) b[i] = a[i] - i;
    int top = 1; st[top] = b[1]; f[1] = 1;
    for (int i = 2; i <= n; i++) {
        int l = 1, r = top, ans = 0;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (st[mid] <= b[i]) ans = mid, l = mid + 1;
                else r = mid - 1;
        }
        f[i] = ans + 1; st[ans + 1] = b[i];
        top = max(ans + 1, top);
    }
    return n - top;
}
int solve2(int n) {
    for (int i = 0; i <= n; i++)
        v[f[i]].push_back(i), g[i] = 1ll << 60;
    g[0] = 0, b[0] = -INT_MAX;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < v[f[i] - 1].size(); j++) {
            int x = v[f[i] - 1][j];
            if (x > i) break;
            if (b[x] > b[i]) continue;
            for (int k = x; k <= i; k++)
                s1[k] = abs(b[x] - b[k]), s2[k] = abs(b[i] - b[k]);
            for (int k = x + 1; k <= i; k++)
                s1[k] += s1[k - 1], s2[k] += s2[k - 1];
            for (int k = x; k < i; k++)
                g[i] = min(g[i], g[x] + s1[k] - s1[x] + s2[i] - s2[k]);
        }
    return g[n];
}
main() {
    int n; read(n);
    for (int i = 1; i <= n; i++) read(a[i]);
    a[++n] = INT_MAX;
    cout << solve1(n) << "\n";
    cout << solve2(n) << "\n";
    return 0;
}
