#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <vector>
#include <bitset>
#include <functional>

using namespace std;

#define LL long long
const int INF = 0x3f3f3f3f;

int n, m;
int s[100009], nt[200009], e[200009];
int out[100009], vis[100009][2], v, ss;
int cnt, flag[100009];

struct node {
	int x, y;
} pre, nt1;

int dfs(int k) {
	flag[k] = 1;
	for (int i = s[k]; ~i; i = nt[i]) {
		if (flag[e[i]] == 1) return 1;
		else if (flag[e[i]] == 0) {
			if (dfs(e[i])) return 1;
		}
	}
	flag[k] = 2;
	return 0;
}

int main() {
	while (~scanf("%d %d", &n, &m)) {
		cnt = 0;
		memset(s, -1, sizeof s);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &out[i]);
			for (int j = 0; j < out[i]; j++) {
				scanf("%d", &v);
				nt[cnt] = s[i], s[i] = cnt, e[cnt++] = v;
			}
		}
		scanf("%d", &ss);
		memset(vis, 0, sizeof vis);
		memset(flag, 0, sizeof flag);
		pre.x = ss, pre.y = 0;
		vis[ss][0] = -1;
		queue<node>q;
		q.push(pre);
		while (!q.empty()) {
			pre = q.front();
			q.pop();
			for (int i = s[pre.x]; ~i; i = nt[i]) {
				if (!vis[e[i]][pre.y ^ 1]) {
					vis[e[i]][pre.y ^ 1] = pre.x;
					nt1.x = e[i], nt1.y = pre.y ^ 1;
					q.push(nt1);
				}
			}
		}
		int flag = 0;
		for (int i = 1; i <= n; i++) {
			if ((!out[i]) && vis[i][1]) {
				printf("Win\n");
				int now = 1, k = i;
				vector<int>ans;
				while (k != -1) {
					ans.push_back(k);
					k = vis[k][now];
					now ^= 1;
				}
				for (int j = ans.size() - 1; j >= 0; j--) {
//                    if (j) printf("%d ", ans[j]);
//                    else printf("%d\n", ans[j]);
					printf("%d ", ans[j]);
				}
				flag = 1;
				break;
			}
		}
		if (!flag) {
			if (dfs(ss)) printf("Draw\n");
			else printf("Lose\n");
		}
	}
	return 0;
}
