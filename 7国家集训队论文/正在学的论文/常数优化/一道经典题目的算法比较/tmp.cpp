// ���������Ż����ر���
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<string>
using namespace std;
int n, m, V[210], W[210], C[210];
int f[20010], q[20010];

int calc(int i, int u, int k) {
	return f[u + k*V[i]] - k*W[i];
}

int main() {
	cin >> n >> m;
	memset(f, 0xcf, sizeof(f)); // -INF
	f[0] = 0;
	// ��Ʒ����
	for (int i = 1; i <= n; i++) {
		scanf("%d%d", &V[i],&C[i]);
		W[i]=V[i];
		// ����V[i]������
		for (int u = 0; u < V[i]; u++) {
			// ������������
			int l = 1, r = 0;
			// ������ĺ�ѡ���ϲ������
			int maxp = (m - u) / V[i];
			for (int k = maxp - 1; k >= max(maxp - C[i], 0); k--) {
				while (l <= r && calc(i, u, q[r]) <= calc(i, u, k)) r--;
				q[++r] = k;
			}
			// ����ѭ��ÿ��״̬
			for (int p = maxp; p >= 0; p--) {
				// �ų���ʱ����
				while (l <= r && q[l] > p - 1) l++;
				// ȡ��ͷ����״̬ת��
				if (l <= r)
					f[u + p*V[i]] = max(f[u + p*V[i]], calc(i, u, q[l]) + p*W[i]);
				// �����¾��ߣ�ͬʱά����β������
				if (p - C[i] - 1 >= 0) {
					while (l <= r && calc(i, u, q[r]) <= calc(i, u, p - C[i] - 1)) r--;
					q[++r] = p - C[i] - 1;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= m; i++) ans = max(ans, f[i]);
	cout << ans << endl;
}

