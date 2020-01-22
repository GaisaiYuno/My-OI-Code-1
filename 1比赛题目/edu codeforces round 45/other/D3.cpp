#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, x, n) for(int i = x; i < (int)(n); ++i)

int const N = 1000;
char m[N][N + 1];
int n, a, b;
bool swp;

void fix(){
	if (!swp)return;
	f(i, 0, n)f(j, 0, n)if (i != j){
		if (m[i][j] == '1')m[i][j] = '0';
		else m[i][j] = '1';
	}
}

void ad(int i, int j) { m[i][j] = '1', m[j][i] = '1'; }

int main(){
	scanf("%d%d%d", &n, &a, &b);
	f(i, 0, n)f(j, 0, n)m[i][j] = '0';
	if (a != 1 && b != 1) { printf("NO\n"); return 0; }
	if (a == 1 && b == 1 && n > 1 && n <= 3) { printf("NO\n"); return 0; }
	if (a == 1)swap(a, b), swp = true;
	int z = a - 1;
	f(i, z + 1, n)ad(i - 1, i);
	fix();
	printf("YES\n");
	f(i, 0, n)printf("%s\n", m[i]);
}
