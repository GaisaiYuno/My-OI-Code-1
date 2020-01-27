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
int f[maxn+5];//f[j]:小于j的最大a[i] 
int main(){
	int ans=0;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	sort(a+1,a+1+n);
	n=unique(a+1,a+1+n)-a-1;
	for(int i=1;i<=n;i++){
		for(int j=a[i]+1;j<=a[i+1];j++) f[j]=a[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=2;j*a[i]<=a[n];j++){
			ans=max(ans,f[j*a[i]]%a[i]);
		}
		ans=max(ans,a[n]%a[i]);
	}
	printf("%d\n",ans);
}
