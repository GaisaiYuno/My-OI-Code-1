#include<cstdio>
int n,q,a[1005],b[1005],c[1005],ans;
bool l;
bool aa(int x,int y){
	bool f=0;
	while(y){
		if(x%10!=y%10){
			f=1;
			break;
		}
		x/=10;
		y/=10;
	}
	return f;
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=q;i++)
		scanf("%d %d",&c[i],&b[i]);
	for(int j=1;j<=q;j++){
		ans=100000000;
		l=0;
		for(int i=1;i<=n;i++){
			if(aa(a[i],b[j])==0)
				if(a[i]<ans){
					ans=a[i];
					l=1;
				}
		}
		if(l)
			printf("%d\n",ans);
		else
			printf("-1\n");
	}
	return 0;
}
