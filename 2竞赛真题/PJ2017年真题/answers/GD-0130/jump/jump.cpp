#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
#define PianFen1 if(cnt<k){printf("-1");return 0;}
#define PianFen2 if((d==1)&&(all>=k)){printf("0");return 0;}
int n,m,d,k;
int all,cnt;
int x[100001];
int s[500001];
int f[500001];
int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;++i){
		scanf("%d%d",x+i,s+i);
		all+=s[i];
		cnt+=s[i]>0?s[i]:0;
	}
	PianFen1;
	PianFen2;
	int maxuse=0,doc=0,minuse=0x7fffffff;
	for(int i=1;i<=n;++i){
		if(s[i]>0){
			doc+=s[i];
			maxuse=max(maxuse,x[i]-x[i-1]);
			minuse=min(minuse,x[i]-x[i-1]);
		}else if(((x[i+1]-x[i-1]>maxuse)||(x[i+1]-x[i-1]<minuse))&&(all+s[i]>=k)){
			doc+=s[i];
			maxuse=max(maxuse,x[i]-x[i-1]);
			minuse=min(minuse,x[i]-x[i-1]);
		}
		if(doc>=k){
			printf("%d",max(maxuse-d,d-minuse));
			return 0;
		}
	}
	printf("-1");
}
