#include<cstdio>
#include<algorithm>
using namespace std;
const int mod[10]={1,10,100,1000,10000,100000,100000,1000000,10000000,100000000};
int n,q,len,b,a[1005],l[1005];
int getlen(int x){
	int ret=0;
	do{
		ret++;
		x/=10;
	}while(x);
	return ret;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		l[i]=getlen(a[i]);
	}
	while(q--){
		scanf("%d%d",&len,&b);
		len=getlen(b);
		bool flag=false;
		for(int i=1;i<=n;i++){
			if(l[i]>=len&&a[i]%mod[len]==b){
				printf("%d\n",a[i]);
				flag=true;
				break;
			}
		}
		if(!flag){
			puts("-1");
		}
	}
	return 0;
}
