#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 1000000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}

int n;
int a[maxn+5];
int calc(int x){
	int ans=0;
	for(int i=2;;i++){
		int p=lower_bound(a+1,a+1+n,i*x)-a-1;
		if(p>0) ans=max(ans,a[p]%x);
		if(i*x>a[n]) break;
	}
	return ans;
}
int main(){
//	freopen("rest3.in","r",stdin);
//	freopen("rest.in","r",stdin);
//	freopen("rest.out","w",stdout);
	int ans=0;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		ans=max(ans,calc(a[i]));
	}	
	printf("%d\n",ans);
}
