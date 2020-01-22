#include<iostream>
#include<cstdio>
#include<cstring>
using  namespace std;
const int N = 320005;
int sum[N], ans[N];
 
inline int Lowbit(int x) {
    return x & -x;
}
 
void ChangeSum(int p, int x) {
    for (; p < N; p += Lowbit(p)) sum[p] += x; 
}
 
int QuerySum(int p) {
    int ans = 0;
    for (; p > 0; p -= Lowbit(p)) 
        ans += sum[p];
    return ans;
}
 
int main() {
	freopen("stars.in","r",stdin);
	freopen("stars.out","w",stdout);
    int n; scanf("%d", &n);
    memset(sum, 0, sizeof(sum));
    for (int i = 0; i < n; i++) {
        int x, y; scanf("%d%d", &x, &y);
        x++;
        ans[QuerySum(x)]++;
        ChangeSum(x, 1);
    }
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}
