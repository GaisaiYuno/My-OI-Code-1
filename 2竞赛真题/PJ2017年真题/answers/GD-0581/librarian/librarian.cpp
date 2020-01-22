#include <iostream>
#include <cstdio>
using namespace std;	
int N, Q, A[1001];

int main(){
	freopen("librarian.in", "r", stdin);
	freopen("librarian.out", "w", stdout);

	scanf("%d %d", &N, &Q);
	for (int i=0; i<N; i++) scanf("%d", &A[i]);
	
	while(Q--){
		int c, num, mo=1, ans=1<<30;
		scanf("%d %d", &c, &num);
		while (c--) mo*=10;
		for(int i=0; i<N; i++){
			if (A[i]<num) continue;
			if (A[i]%mo==num&&A[i]<ans) ans=A[i]; 
		}
		if (ans==1<<30) printf("-1\n");
		else printf("%d\n", ans);
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
