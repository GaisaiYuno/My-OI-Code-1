#include<iostream>
#include<cstdio>
#define maxn 100000
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
int main(){
	freopen("rest3.in","r",stdin);
	int ans=0;
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	int maxi=0,maxj=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i]>a[j]&&a[i]%a[j]>ans){
				ans=a[i]%a[j];
				maxi=i;
				maxj=j;
			}
		}
	}
	printf("%d %d %d\n",ans,a[maxi],a[maxj]);
}
