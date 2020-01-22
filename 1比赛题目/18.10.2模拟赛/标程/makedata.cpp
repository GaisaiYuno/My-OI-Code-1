#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<map>
#include<utility> 
#include<algorithm>
#define maxv 10
#define maxn 5
#define maxm 20
using namespace std;
pair<int, int> e[1000005]; // 保存数据
map< pair<int, int>, bool > h; // 防止重边
// 先生成一棵树，保证连通
int random(int n) {
    return (long long)rand() * rand() % n;
}
int main() {
	srand(time(NULL));
	int n=random(maxn)+3;
	int m=random(n*(n-1)/2-n+1)+n-1;
	int x=random(maxv)+1; 
	printf("%d %d %d\n",n,m,x);
	for (int i = 1; i < n; i++) {
		int fa = random(i) + 1;
		e[i] = make_pair(fa, i + 1);
		h[e[i]] = h[make_pair(i + 1, fa)] = 1;
	}
// 再生成剩余的 m-n+1 条边
	for (int i = n; i <= m; i++) {
		int x, y;
		do {
			x = random(n) + 1, y = random(n) + 1;
		} while (x == y || h[make_pair(x, y)]);
		e[i] = make_pair(x, y);
		h[e[i]] = h[make_pair(y, x)] = 1;
	}
// 随机打乱，输出
	random_shuffle(e + 1, e + m + 1);
	for (int i = 1; i <= m; i++)
		printf("%d %d %d\n", e[i].first, e[i].second,random(maxv)+1);
}
