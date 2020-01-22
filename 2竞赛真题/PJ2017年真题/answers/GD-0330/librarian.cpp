#include <cstdio>
#include <algorithm>
using namespace std;
int a[1010]={0},q,n,x,y,m=0;
bool f=1;

int quick(int x){
	int ans=1,nn=10;
	while(x){
		if(x&1)ans*=nn;
		nn*=nn;
		x/=2;
	}
	return ans;
}

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);//printf("%d\n",quick(10));
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+1+n);
	for(int j=1;j<=q;j++){
		scanf("%d%d",&x,&y);
		long long m=quick(x);
		for(int i=1;i<=n;i++){
			if(a[i]%m==y){
			    printf("%d\n",a[i]);
				f=0;
				break;
			}
		}
		if(f)printf("-1\n");
		f=1;
		m=0;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
