#include<iostream>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;

const int N = 9e5 + 100;
typedef long long ll;
typedef pair<ll, int> P;
#define fi first
#define se second
#define ls rt << 1
#define rs rt << 1 | 1
#define lson rt << 1, l, mid
#define rson rt << 1 | 1, mid + 1, r

struct Edge {
    int v;
    ll w;
    int next;
};

int id[2][N * 4];
int tot;
int head[N];
Edge edge[N * 4];
int sz;

void init() {
    sz = 0;
    tot = 0;
    memset(head, -1, sizeof(head));
}

void add_edge(int u, int v, ll w) {
	printf("%d->%d\n",u,v);
    edge[tot].v = v;
    edge[tot].w = w;
    edge[tot].next = head[u];
    head[u] = tot++;
}

void build(int rt, int l, int r, int t) {
    id[t][rt] = ++sz;
    if (l == r) {
        if (t == 0) {
            add_edge(id[t][rt], l, 0);
        }
        else {
            add_edge(l, id[t][rt], 0);
        }
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, t);
    build(rson, t);
    if (t == 0) {
        add_edge(id[t][rt], id[t][ls], 0);
        add_edge(id[t][rt], id[t][rs], 0);
    }
    else {
        add_edge(id[t][ls], id[t][rt], 0);
        add_edge(id[t][rs], id[t][rt], 0);
    }
}

int ql, qr;
int goal_v;

void update(int rt, int l, int r, int t, ll w) {
    if (ql <= l && r <= qr) {
        if (t == 0) {
            add_edge(goal_v, id[t][rt], w);
        }
        else {
            add_edge(id[t][rt], goal_v, w);
        }
        return;
    }
    int mid = (l + r) >> 1;
    if (ql <= mid) {
        update(lson, t, w);
    }
    if (qr > mid) {
        update(rson, t, w);
    }
}

const ll INF = (1LL) << 62;
bool vis[N];
ll dis[N];

priority_queue<P, vector<P>, greater<P> >que;

void solve(int s) {
    for (int i = 1; i <= sz; i++) {
        dis[i] = INF;
    }
    dis[s] = 0;
    memset(vis, false, sizeof(vis));
    while (!que.empty()) que.pop();
    que.push(P(0, s));
    while (!que.empty()) {
        int u = que.top().se;
        que.pop();
        if (vis[u]) continue;
        vis[u] = true;
        for (int i = head[u]; ~i; i = edge[i].next) {
            int v = edge[i].v;
            ll w = edge[i].w;
            if (dis[v] > dis[u] + w) {
                dis[v] = dis[u] + w;
                que.push(P(dis[v], v));
            }
        }
    }
}

int main() {
    init();
    int n, q, s;
    scanf("%d%d%d",  &n, &q, &s);
    sz = n;
    for (int i = 0; i < 2; i++) {
        build(1, 1, n, i);
    }
    for (int i = 0; i < q; i++) {
        int op, v;
        ll w;
        scanf("%d", &op);
        if (op == 1) {
            scanf("%d%d%lld", &v, &ql, &w);
            add_edge(v, ql, w);
        }
        else {
            op -= 2;
            scanf("%d%d%d%lld", &v, &ql, &qr, &w);
            goal_v = v;
            update(1, 1, n, op, w);
        }
    }
    solve(s);
    for (int i = 1; i <= n; i++) {
        if (i > 1) printf(" ");
        if (dis[i] == INF) printf("-1");
        else printf("%lld", dis[i]);
    }
    printf("\n");
    return 0;
}
