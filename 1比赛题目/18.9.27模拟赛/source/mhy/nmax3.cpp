#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#define MAXN 500005
using namespace std;
inline int read(){
	char ch=getchar();
	int x=0;
	while (ch<='9'&&ch>='0'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int cnt;
int a[MAXN];
double calc(){
	int maxi=0;
	double ans=-0x7fffffff;
	for (int i=0;i<(1<<cnt);++i){
		double maxn=-0x7fffffff,sum=0;
		int c=0;
		for (int j=0;j<cnt;++j){
			if (i&(1<<j)){
				++c;
				maxn=max((double)(a[j]),maxn);
				sum+=(double)(a[j]);
			}
		}
		double well=maxn-sum/(double)(c);
		if (well>ans){
			maxi=i;
			ans=well;
		}
	}
	printf("maxi:%d\n",maxi);
	int stk[MAXN];
	memset(stk,0,sizeof(stk));
	int k=0;
	while (maxi){
		if (maxi&1){
			stk[++k]=true;
		}
		else {
			stk[++k]=false;
		}
		maxi>>=1;
	}
	for (int i=k;i>=1;--i){
		printf("%d ",stk[i]);
	}
	printf("\n");
	return ans;
}
int main(){
	freopen("nmax1.in","r",stdin);
//	freopen("nmax.out","w",stdout);
	int n=read();
	while (n--){
		int op=read();
		if (op==1){
			int x=read();
			a[cnt++]=x;
		}
		else {
			printf("%f\n",calc());
		}
	}
}
