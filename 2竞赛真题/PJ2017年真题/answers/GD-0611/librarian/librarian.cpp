#include<cstdio>
#include<algorithm>
using namespace std;
const int ww[8]={0,10,100,1000,10000,100000,1000000,10000000};
int n,q,num[1005],t1,t2;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++) scanf("%d",&num[i]);
	sort(num,num+n);
	for(int i=0;i<q;i++){
		scanf("%d%d",&t1,&t2);
		int ans=-1;
		for(int i=0;i<n;i++)
			if(num[i]%ww[t1]==t2) {ans=num[i];break;}
		printf("%d\n",ans);
	}
	return 0;
}
