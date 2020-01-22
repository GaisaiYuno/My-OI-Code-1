#include<bits/stdc++.h>
#define INT 2147483647
using namespace std;
int n,q,book[1010],num,ques;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++) scanf("%d",&book[i]);
	sort(book+1,book+n+1);
	while(q--){
		scanf("%d%d",&num,&ques);
		int tot=1,flag=0;
		while(num--) tot*=10;
		for(int i=1;i<=n;i++){
			int db=book[i]%tot;
			if(db==ques){
				printf("%d\n",book[i]);
				flag=1;break;
			}
		}
		if(!flag) printf("-1\n");
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
