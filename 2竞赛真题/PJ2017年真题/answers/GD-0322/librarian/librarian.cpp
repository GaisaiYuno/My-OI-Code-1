#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,a[1010],len[1010],b[1010],ck,aa[50]={1,10,100,1000,10000,100000,1000000,10000000,100000000};
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for (int i=1;i<=n;++i){
		scanf("%d",a+i);
	}
	for (int i=1;i<=m;++i){
		scanf("%d%d",len+i,b+i);
	}
	sort(a+1,a+n+1);
	for (int i=1;i<=m;++i){
		ck=0;
		for (int j=1;j<=n;++j){
			if (a[j]%aa[len[i]]==b[i]){
				ck=1;
				printf("%d\n",a[j]);
				break;
			}
		}
		if (ck==0){
			printf("%d\n",-1);
		}
	}
	return 0;
}
/*
5 5
2123
1123
23
24
24
2 23
3 123
3 124
2 12
2 12
*/
