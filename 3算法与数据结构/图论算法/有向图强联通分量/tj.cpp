#include <cstdio>
#include <algorithm>
#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int N = 5000, M = 10000;
int head[N], to[M], nxt[M], _; 
char ans[N];
bool vis[N];
void add(int a,int b) {
	printf("%d %d\n",a,b);
    to[++_] = b;
    nxt[_]  = head[a];
    head[a] = _;
}
int n, m;
queue<int>q;
bool bfs(int s) {
    memset(vis, 0, sizeof(vis));
    vis[s] = 1;
    while(!q.empty())q.pop();
    q.push(s);
    while(!q.empty()) {
        int u = q.front();
        q.pop();
        for(int i=head[u];i;i=nxt[i]) {
            if(!vis[to[i]]) {
                vis[to[i]] = 1;
                q.push(to[i]);
            }
        }
    }
    for(int i=1;i<=n;i++) {
        if(vis[i]&&vis[n+i]) return 0;
    }
    return 1;
}
int main() {
    scanf("%d%d", &n, &m);
    char s1[3], s2[3];
    for(int i=1, x, y;i<=m;i++) {
        scanf("%d%s%d%s", &x, s1, &y, s2);
        int tx, ty;
        if(s1[0]=='Y') tx = 1;else tx = 0;
        if(s2[0]=='Y') ty = 1;else ty = 0;
        add((1-tx)*n+x,ty*n+y);
        add((1-ty)*n+y,tx*n+x);
    }
    for(int i=1;i<=n;i++) {
        int t = bfs(i+n), f = bfs(i);
        if(!t&&!f) {
            puts("IMPOSSIBLE");
            return 0;
        }
        if(t&&f) ans[i] = '?';
        else if(!f) ans[i] = 'Y';
        else if(!t) ans[i] = 'N';
    }
    for(int i=1;i<=n;i++) {
        putchar(ans[i]);
    }
}
