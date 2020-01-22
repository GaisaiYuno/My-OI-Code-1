#include <cstdio>
#include <climits>
using namespace std;
int n,d,k,x[500010],s[500010];
long long w[500010],cj;
int max(int a,int b) {
	return ((a)>(b)?(a):(b));
}
bool check(int num) {
	long long score = 0;
	int current = 0;
	while (score < k && current < n && x[current+1]-x[current] <= num) {
		int MAX = INT_MAX*-1,MAX_POS = current;
		if (current != 0 && w[current]-score>cj) return false;
		for (int i = current+1;i<=n;i++) {
			if (x[i]-x[current] < num) {
				if (s[i] >= MAX) {
					MAX = s[i];
					if (score + MAX >= k) return true;
					MAX_POS = i;
				}
			} else {
				if (MAX < 0 && x[i]-x[MAX_POS] >= num) {
					MAX = INT_MAX*-1;
					for (int j = i-1;j>current;--j) {
						if (x[i]-x[j] < num) {
							if (s[i]>=MAX){
								MAX = s[i];
								if (score + MAX >= k) return true;
								MAX_POS = i;
							}
						} else break;
					}
				}
				break;
			}
		}
		current = MAX_POS;
		score += MAX;
	}
	return score>=k;
}
int main() {
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (int i = 1;i<=n;i++) {
		scanf("%d%d",&x[i],&s[i]);
		if (s[i] >= 0) w[i] = w[i-1]+s[i];
		 else w[i] = w[i-1];	
	}
	if (w[n]<k) {
		printf("%d",-1);
	} else {
		cj = w[n]-k;
		int left = 1,right = x[n],MIN;
		while (left<=right) {
			int mid = (left+right)/2;
			if (check(mid)) {
				MIN = mid;
				right = mid-1;
			} else left = mid+1;
		}
		printf("%d",((MIN>=d)?(MIN-d):(0)));
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
