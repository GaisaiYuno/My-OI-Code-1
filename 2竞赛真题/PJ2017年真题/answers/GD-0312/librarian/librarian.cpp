#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int f[10]={1,10,100,1000,10000,100000,1000000,10000000,100000000,1000000000};
int n,q,a[1010];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	sort(a+1,a+n+1);
	for(int i=1;i<=q;i++){
		int x,y;
		scanf("%d%d",&x,&y);
		bool flag=false;
		for(int j=1;j<=n;j++)
			if(a[j]<y)
				continue;
			else if(a[j]%f[x]==y){
				printf("%d\n",a[j]);
				flag=true;
				break;
			}
		if(!flag)
			puts("-1");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
