#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int book[1010],k,n,m,q,r;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for (int i=0;i<n;i++){
		scanf("%d",&book[i]);
	}
	sort(book,book+n);
	for (int i=0;i<q;i++){
		scanf("%d%d",&k,&m);
		bool f=1;
		for (int j=0;j<n;j++){
			if (book[j]==m) {
				printf("%d\n",book[j]);
				f=0;
				break;
			}
			if (book[j]>m){
				int l=book[j]-m;
				for (r=0;r<k;r++){
					if (l==1||l%10!=0) break;
					l/=10;
				}
				if (r==k) {
					printf("%d\n",book[j]);
					f=0;
					break;
				}
			}
		}
		if (f) printf("-1\n");
	}
	return 0;
}
