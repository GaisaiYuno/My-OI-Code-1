#include<cstdio>
int a[1002],f[9];
int n,m;
void kp(int z,int y){
	int i=z,j=y,n=a[(z+y)/2];
	while (i<=j){
		while (a[i]<n) i++;
		while (a[j]>n) j--;
		if (i<=j){
			int e=a[i]; a[i]=a[j]; a[j]=e;
			i++; j--;
		}
	}
	if (i<y) kp(i,y);
	if (z<j) kp(z,j);
}
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&m);
	a[0]=-1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	kp(1,n);
	f[0]=1;
	for (int i=1;i<=8;i++) f[i]=f[i-1]*10;
	for (int i=1;i<=n;i++){
		int e,s,ans=-1;
		scanf("%d%d",&e,&s);
		for (int j=1;j<=n;j++)
		    if (a[j]%f[e]==s){
				ans=a[j];
				break;
	    	}
	    printf("%d\n",ans);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
