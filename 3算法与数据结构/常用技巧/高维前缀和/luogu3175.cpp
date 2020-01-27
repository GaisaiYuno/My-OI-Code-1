//https://www.luogu.org/blog/yyyuuu/solution-p3175
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 20
#define eps 1e-10
using namespace std;
int n;
double p[(1<<maxn)+5];

int count_1(int x){
	int ans=0;
	while(x){
		if(x&1) ans++;
		x>>=1; 
	}
	return ans;
}

int main(){
	scanf("%d",&n);
	for(int i=0;i<(1<<n);i++) scanf("%lf",&p[i]);
	for(int i=0;i<n;i++){
		for(int j=0;j<(1<<n);j++){
			if(j&(1<<i)) p[j]+=p[j^(1<<i)];
		}
	}
	double ans=0;
	int all=(1<<n)-1;
	for(int i=1;i<=all;i++){
		if(fabs(1-p[all^i])<eps) continue;//·ÀÖ¹³ý0´íÎó
		ans+=pow(-1,count_1(i)-1)*1/(1-p[all^i]);
	}
	if(fabs(ans)<eps) printf("INF");
	else printf("%.10lf",ans);
}
 
