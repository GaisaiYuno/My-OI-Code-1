#include<bits/stdc++.h>
using namespace std;
int n,m,a[100001];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;++i)scanf("%d",&a[i]);
	sort(a,a+n);
	for(int i=0;i<m;++i){
		int x,y,t,s=0;
		scanf("%d%d",&x,&y);
		t=pow(10,x);
		for(int j=0;j<n;++j){
			if(a[j]%t==y){
				printf("%d\n",a[j]);
				s=1;
				break;
			}
		}
		if(!s)printf("-1\n");
	}
	return 0;
}
