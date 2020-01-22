#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,q;
int book[1010];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++)scanf("%d",&book[i]);
	sort(book,book+n);
	for(int i=0;i<q;i++){
		int l,s;
		scanf("%d%d",&l,&s);
		for(int j=0;j<n;j++){
			int want=s,b=book[j];
			while(1){
				if(want&&!b)break;
				if(!want){
					printf("%d\n",book[j]);
					goto to;
				}
				if(want%10!=b%10)break;
				want/=10,b/=10;
			}
		}
		puts("-1");
		to:;
	}
	return 0;
}
