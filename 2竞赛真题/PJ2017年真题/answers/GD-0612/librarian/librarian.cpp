#include<cstdio>
#include<algorithm>
using namespace std;
int pow(int x){
	int ans=1;
	while(x--)ans*=10;
	return ans;
}
int n,q,i;
int a[1001];
bool cmp(int x,int y){return x<y;}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(i=1;i<=n;i++)scanf("%d",&a[i]);
	sort(a+1,a+n+1,cmp);
	int x,b,f=1,len;
	while(q--){
		scanf("%d%d",&len,&x);
		i=1;f=1;
		while(a[i]<x)i++;i--;
		while(i<=n){
			i++;
			b=a[i];
			b%=pow(len);
			if(b==x){f=0;printf("%d\n",a[i]);break;}
		}
		if(f)printf("-1\n");
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
