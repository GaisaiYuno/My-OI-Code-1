#include<cstdio>
#include<algorithm>
using namespace std;
int b[1005],rl[1005],r[1005];
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	int n,q,i,l,a,ans,j,c;
	bool o;
	scanf("%d %d",&n,&q);
	for(i=1;i<=n;i++) scanf("%d",&b[i]);
	for(i=1;i<=q;i++) scanf("%d %d",&rl[i],&r[i]);
	sort(b+1,b+1+n);
	for(i=1;i<=q;i++){
		ans=0;
		for(j=1;j<=n;j++){
			o=true;
			l=rl[i];
			a=r[i];
			c=b[j];
			while(l>0){
				if(c%10!=a%10){
					o=false;break;
				}
				c/=10;
				a/=10;
				l--;
			}
			if(o==true){
				printf("%d\n",b[j]);
				ans++;
				break;
			}
		}
		if(ans==0) printf("-1\n");
	}
	return 0;
}
