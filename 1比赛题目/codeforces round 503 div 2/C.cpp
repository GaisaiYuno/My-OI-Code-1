#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 10005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
int n,m;
struct vote{
	int p;
	long long c;
}v[maxn];
int cmp(vote a,vote b){
	if(a.p==1) return 0;
	if(b.p==1) return 1;
	return a.c<b.c;
}
int cnt_vote[maxn];
int new_cnt[maxn];
int used[maxn];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %I64d",&v[i].p,&v[i].c);
		cnt_vote[v[i].p]++;
	}
	long long ans=INF;
	sort(v+1,v+1+n,cmp);
	for(int i=0;i<n;i++){
		long long sum=0;
		memset(used,0,sizeof(used));
		for(int j=1;j<=m;j++){
			new_cnt[j]=cnt_vote[j];
		}
		for(int j=1;j<=n&&v[j].p!=1;j++){
			if(new_cnt[v[j].p]>i){
				new_cnt[1]++;
				new_cnt[v[j].p]--;
				sum+=v[j].c;
				used[j]=1;
			}
		}
		if(new_cnt[1]<=i){
			for(int j=1;j<=n;j++){
				if(new_cnt[1]>i) break;
				if(!used[j]){
					sum+=v[j].c;
					new_cnt[1]++;
				}
			}
		}
		if(new_cnt[1]>=i) ans=min(sum,ans);
	}
	printf("%I64d\n",ans);
}
