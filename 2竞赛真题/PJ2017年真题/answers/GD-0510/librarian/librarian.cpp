#include<bits/stdc++.h>
using namespace std;
int n,q,i,j,a[1001],b[1001],c[1001],d[1001];
long long p(int s){
	long long x=1;
	for(int k=1;k<=s;k++) x=10*x;
	return x; 
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&a[i]);
	for(i=1;i<=q;i++){
		scanf("%d",&b[i]);
		scanf("%d",&c[i]);
	}
	sort(a+1,a+n+1);
	for(i=1;i<=q;i++){
		for(j=1;j<=n;j++){
			if((a[j]%p(b[i]))==c[i]){
				printf("%d\n",a[j]);
				break;
			} 
			else if(j==n) printf("-1\n");
		}
	}
	return 0;
}
