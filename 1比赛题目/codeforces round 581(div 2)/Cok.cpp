#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<stack>
#include<algorithm>
using namespace std;
namespace fio {
	streambuf* in = cin.rdbuf();
	char bb[1000000], * s = bb, * t = bb;
#define gc() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000),s==t)?EOF:*s++)
#define peek() (s==t&&(t=(s=bb)+in->sgetn(bb,1000000),s==t)?EOF:*s)
	inline int read() {
		int x = 0; char ch = gc();
		while (ch < 48)ch = gc();
		while (ch >= 48)x = x * 10 + ch - 48, ch = gc();
		return x;
	}
	void w(int x) {
		if (x >= 10)w(x / 10);
		putchar(x % 10 + 48);
	}
}using namespace fio;
using fio::w;
namespace jekyll {
	int n, m, k;
	int arr[1000005];
	int las[1000005];
	int dp[1000005];
	vector<int>road[100005];
	bool huaji[105][105];
	int map[105][105];
	void out(int x) {
		if (x != 1)out(las[x]);
		cout << arr[x] << ' ';
	}
	void serve() {
		n = read();
		memset(map, 0x3f, sizeof(map));
		for (int i = 1; i <= n; i++)for (int u = 1; u <= n; u++) {
			map[i][i] = 0;
			while (!isdigit(peek()))gc();
			huaji[i][u] = gc() - 48;
			if (huaji[i][u])map[i][u] = 1;
		}
		for (int i = 1; i <= n; i++)
			for (int u = 1; u <= n; u++)
				for (int j = 1; j <= n; j++)
					map[u][j] = min(map[u][j], map[u][i] + map[i][j]);
		m = read();
		for (int i = 1; i <= m; i++)arr[i] = read();
		memset(dp, 0x3f, sizeof(dp));
		dp[1] = 1;
		for (int i = 2; i <= m; i++) {
			for (int u = max(i - n, 1); u < i; u++) {
				if (map[arr[u]][arr[i]] == i - u)if (dp[i] > dp[u] + 1)dp[i] = dp[u] + 1, las[i] = u;
			}
		}
		cout << dp[m] << endl;
		out(m);
	}
}
int main() { int t = 1; while (t--)jekyll::serve(); }
