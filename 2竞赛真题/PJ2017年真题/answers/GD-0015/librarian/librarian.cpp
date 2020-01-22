#include<cstdio>
using namespace std;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,book[1001];
	const int mi[]={1,10,100,1000,10000,100000,1000000,10000000};
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",book+i);
	for(int i=0;i<q;i++){
		int len,code,minans=10000001;
		scanf("%d%d",&len,&code);
		for(int j=0;j<n;j++)
			if(book[j]%mi[len]==code && book[j]<minans) minans=book[j];
		if(minans==10000001) printf("-1\n");
		else printf("%d\n",minans);
	}
}
