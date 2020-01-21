#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
const int N = 880000;
const int SZ = 5500000;
using namespace std;
int read() {
    char ch = getchar(); int x = 0, f = 1;
    while(ch < '0' || ch > '9') {if(ch == '-') f = -1; ch = getchar();}
    while(ch >= '0' && ch <= '9') {x = (x << 1) + (x << 3)  - '0' + ch; ch = getchar();}
    return x * f;
}
struct ask{int c, e[4];}q[N]; 
int f[N], st[SZ], u[N], v[N], del[N], ans[N], top, tim, n, m, k;
 
int find(int x) {
    if(f[x] == x) return x;
    st[++top] = x; st[++top] = f[x];
    f[x] = find(f[x]);
}
 
void Union(int u, int v) {
    int fu = find(u), fv = find(v);
    if(fu != fv) {
        st[++top] = fu; st[++top] = f[fu];
        f[fu] = fv;
    }
}
 
void Del(int L, int R) {
    for(int i = L; i <= R; ++i) 
        for(int j = 0;j < q[i].c; ++j) 
            del[q[i].e[j]] = tim;
}
void Add(int L, int R) {
    for(int i = L;i <= R; ++i) 
        for(int j = 0;j < q[i].c; ++j)
            if(del[q[i].e[j]] != tim) Union(u[q[i].e[j]], v[q[i].e[j]]);
}
void restore(int cur) {for( ;cur != top; top -= 2) f[st[top - 1]] = st[top];}
 
void cdq(int L, int R) {
    int now = top;
    if(L == R) {
        bool flag = true;
        for(int i = 0;i < q[L].c && flag; ++i) 
            if(find(u[q[L].e[i]]) != find(v[q[L].e[i]])) flag = false;
        restore(now);
        ans[L] = flag;
        return;
    }
    int mid = L + R >> 1; ++tim;
    Del(L, mid); Add(mid + 1, R);
    cdq(L, mid); restore(now); ++tim;
    Del(mid + 1, R); Add(L, mid);
    cdq(mid + 1, R); restore(now);
}
 
int main() {
    n = read(); m = read(); top = 0;
    for(int i = 1;i <= n; ++i) f[i] = i;
    for(int i = 1;i <= m; ++i) {u[i] = read(); v[i] = read();}
    k = read(); tim = 1;
    for(int i = 1;i <= k; ++i) {
        q[i].c = read();
        for(int j = 0;j < q[i].c; ++j) del[q[i].e[j] = read()] = tim;
    }
    for(int i = 1;i <= m; ++i) 
    if(del[i] != tim)
        Union(u[i], v[i]);
    cdq(1, k);
    for(int i = 1;i <= k; ++i)
        puts(ans[i] ? "Connected" : "Disconnected");
    return 0;
}

