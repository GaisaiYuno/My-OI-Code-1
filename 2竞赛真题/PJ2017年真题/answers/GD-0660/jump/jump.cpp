#include<cstdio>
#include<algorithm>
using namespace std;
int N,D,K,sum,X[500001],S[500001],T,MIN=10293284,MIN_L;
bool B[500001];
void DFS(int num){
	int last=X[1],MAX=-1,MIN_T=35364536;
	bool flag=false;
	for(int i=1;i<=N;i++) if(B[i]){MAX=max(MAX,X[i]-last); last=X[i];} last=X[1];
	for(int i=2;i<=N;i++) if(B[i]){MIN_T=min(MIN_T,X[i]-last); last=X[i];}
	if(MIN>MAX) MIN_L=min(MIN_L,MIN_T);
	MIN=min(MAX,MIN);
	if(MAX>=num) return;
	for(int i=1;i<=N;i++){
		if(!B[i] && T+S[i]>=K){B[i]=true; DFS(MAX); flag=true; B[i]=false;}
		else if(B[i] && T-S[i]>=K){B[i]=false; DFS(MAX); flag=true; B[i]=true;}
	}
	if(!flag) return;
}
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d %d %d",&N,&D,&K);
	for(int i=1;i<=N;i++){scanf("%d %d",&X[i],&S[i]); if(S[i]>=1){T+=S[i]; B[i]=true;}}
	MIN_L=X[1];
	if(T<K) printf("-1");
	else{
		DFS(23892182);
		int ans=MIN;		
		int less=MIN_L,last=X[1];
		printf("%d",max(abs(D-ans),abs(D-less)));
	}
	fclose(stdin);
	fclose(stdout);
}
