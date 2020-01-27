#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#define maxn 100005 
using namespace std;
int st[maxn][31];
int a[maxn],cnt[maxn];
int n,q;
void init(){
	int k=1;
	st[1][0]=1;
	for(int i=2; i<=n; i++) {
		if(a[i]==a[i-1]) st[i][0]=++k;
		else st[i][0]=k=1;
	}
	for(int j=1;j<=20;j++){
		for(int i=(1<<j);i<=n;i++){
			st[i][j]=max(st[i][j-1],st[i-(1<<(j-1))][j-1]);
//			printf("%d ",st[i][j]);
		}
//		printf("\n");
	} 
}
int query(int l,int r){
	int x=log2(r-l+1);
//	printf("%d %d",l,r);
	return max(st[l+(1<<x)-1][x],st[r][x]);
}
int main(){
	int l,r;
	while(scanf("%d",&n)!=EOF&&n!=0){
		scanf("%d",&q);
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		memset(cnt,0,sizeof(cnt));
		int k=1;
		cnt[1]=1;
		for(int i=2;i<=n;i++){
			if(a[i]==a[i-1]){
				cnt[i]=k++;
			}
			else cnt[i]=k=1;
		}
		init();
		while(q--){
			 scanf("%d %d",&l,&r); 
		//	 if(l==r){
		//	 	printf("1\n");
		//	 	continue;
		//	 }
		
		
//			 int tmp=l;
//             while((tmp<=r&&a[tmp]==a[tmp-1])||tmp==1) tmp++;
//             printf("%d\n",tmp);
//             int ans=max(tmp-l,query(tmp,r));

			int cnt=0,pos=r;
			int ans;
			for(int i=l; i<=r; i++) {
				if(a[i]==a[l]) {
					cnt++;
				} else {
					pos=i;
					break;
				}
			}
			if(pos==r)  ans=cnt;
			else{
				int t=query(pos,r);
				 ans=max(cnt,t);
			}
			
//            printf("debug:%d %d %d \n",cnt,pos,t);
            printf("%d\n",ans);
		}
	} 
}
