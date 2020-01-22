#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
const int Size=1001;
int books[Size],need[Size],len[Size];
bool judge(int book,int num) {
	int temp=book,temp2=need[num];
	int now=len[num];
	while(now--) {
		if(temp%10!=temp2%10)
			return false;
		temp/=10;
		temp2/=10;
	}
	return true;
}
int main() {
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q;
	bool flag;
	scanf("%d %d",&n,&q);
	for(int i=1; i<=n; i++)
		scanf("%d",&books[i]);
	for(int i=1; i<=q; i++)
		scanf("%d %d",&len[i],&need[i]);
	sort(books+1,books+1+n);
	for(int i=1; i<=q; i++) {
		flag=false;
		for(int j=1; j<=n; j++) {
			if(judge(books[j],i)) {
				printf("%d\n",books[j]);
				flag=true;
				break;
			}
		}
		if(!flag)	//·Ç0ÎªÕæ 
			printf("-1\n");
	}
	return 0;
}
