#include <iostream>
#include <cstdio>
#include <vector>
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
int main(){
	freopen("nmax1.in","r",stdin);
//	freopen("nmax.out","w",stdout);
	int n=read();
	double mean=0,maxn=-0x7ffffff;
	int cnt=0;
	while (n--){
		int op=read();
		if (op==1){
			++cnt;
			int add=read();
			maxn=max(maxn,(double)add);
			mean=(mean*((double)(cnt)-1.00)+(double)(add))/(double)(cnt);
		}
		else {
			printf("%f\n",maxn-mean);
		}
	}
}
//delta(max) > delta(mean)
