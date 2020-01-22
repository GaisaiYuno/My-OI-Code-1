#include<cstdio>
int n,d,k,t1[500001],t2[500001],cnt,teans,compdist,ans,teans1;
bool _check[500001];
main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for (register int i=1;i<=n;i++){
		scanf("%d%d",&t1[i],&t2[i]);
		if (t2>0) cnt+=t2[i],_check[i]=true;
	}
	if (cnt<k) {printf("-1"); return 0;}
	for (register int i=1;i<=n;i++){
		if (t2[i]>0 /*||(t2[i]<0 && cnt+t2[i]>k && t1[i+1]-t1[i-1]>=teans1)*/) {
			cnt+=t2[i];
			teans=teans>(t1[i]-compdist<d? d-t1[i]+compdist:t1[i]-compdist-d)? teans:(t1[i]-compdist<d? d-t1[i]+compdist:t1[i]-compdist-d);
			compdist=t1[i];
			if (cnt>=k){
				ans=teans;
//				return 0;
			}
		}
	}
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
/*
7 4 10
2 6
5 -3
10 3
11 -3
13 1
17 6
20 2

*/
