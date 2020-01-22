#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int a[1001];
int b[1001];
int c[1001];
int n,q;
int f(int x){
	int s=1;
	for(int i=1;i<=x;i++)s=s*10;
	return s;
}
int main(){//10000000
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		scanf("%d%d",&b[i],&c[i]);
		b[i]=f(b[i]); 
	}
	for(int i=1;i<=q;i++){
		bool s=0;
		for(int j=1;j<=n;j++){
			if(a[j]%b[i]==c[i]){
				printf("%d\n",a[j]);
				s=1;
				break;
			}
		}
		if(s==0)printf("-1\n");
	}
}
