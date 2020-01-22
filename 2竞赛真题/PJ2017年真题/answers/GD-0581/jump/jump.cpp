#include <iostream>
#include <cstdio>
using namespace std;
int N, D, K;
int jl, jr;
bool tag=false;
int book[500005];
int V[500005][2];
int MX;

bool Jump(int curr){
	int c;
	for(int i=jl; i<=jr; i++){
		if (curr+i>MX) break;
		for(int j=0; j<N; j++){
			if(V[j][0]>curr&&(V[j][0]-curr)%i==0){
				c=book[curr]+V[j][1];
				if (c>=K) return true;
				if (c>book[V[j][0]]){
					book[V[j][0]]=c;
					if (Jump(V[j][0])) return true;
				}
			}
		}
	}
	return false;
}

int main(){
	freopen("jump.in", "r", stdin);
	freopen("jump.out", "w", stdout);
	
	int l=0, r=0, m, ans=1<<30;
	scanf("%d %d %d", &N, &D, &K);
	for(int i=0; i<N; i++) {
		scanf("%d %d", &V[i][0], &V[i][1]);
		if (V[i][1]>=r) r=V[i][1];
	}
	MX=r;
	r -= D;
	while(l<=r){
		m=(l+r)/2;
		if (m>=D) jl=1; else jl=D-m;
		if (m+D>N) jr=N; else jr=m+D;
		for (int i=0; i<=N; i++) book[i]=0;
		if (Jump(0)) { ans=m; r=m-1; }
		else l=m+1;
	}
	
	if (ans==1<<30) printf("-1");
	else printf("%d", ans);
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
