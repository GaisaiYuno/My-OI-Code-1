#include<iostream> 
#include<cstring>
#include<cstdio>
#include<algorithm>
#define maxn 1000005
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int a[maxn];
int n,pos;
int main(){
	while(scanf("%d",&n)){
		if(n==0) break;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++) a[i]=qread(); 
		sort(a+1,a+1+n);
		pos=0;
		for(int i=1;i<n;i++){
			if(a[i]!=a[i-1]&&a[i]!=a[i+1]){
				 pos=i;
				 break;
			}
		}
		if(pos!=0) printf("%d\n",a[pos]);
		else if(a[1]!=a[2]) printf("%d\n",a[1]);
		else printf("%d\n",a[n]);
	}
}
