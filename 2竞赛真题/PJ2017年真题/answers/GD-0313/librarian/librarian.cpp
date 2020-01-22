#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
using namespace std;
int a[1001],b[1001],c[1001];
bool f[1001];
long long fun(int x,int y){
	if(y==1)
		return x;
	else
		return x*fun(x,y-1);
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	bool xx;
	int n,p,s=0;
	memset(f,true,sizeof(f));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=p;++i)
		scanf("%d%d",&b[i],&c[i]);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(a[j]<a[j+1])
				swap(a[j],a[j+1]);

	for(int i=1;i<=p;++i){
		xx=false;
		for(int j=n;j>=1;--j){
			int TMD=a[j]%fun(10,b[i]);
			if(TMD==c[i]&&f[j]==true){
				printf("%d\n",a[j]);
				s++;
				f[j]=false;
				xx=true;
				break;
			}
		}
		if(xx==false)
			printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
