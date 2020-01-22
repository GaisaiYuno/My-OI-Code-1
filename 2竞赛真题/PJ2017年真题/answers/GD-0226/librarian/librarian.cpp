#include <cstdio>
#include <cstring>
int k[1005],o[1005]={1},na[1005],qa[1005],jj[1005];
int xjb(int a,int b){
	if(a>b) return b;
	else return a;
}
int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout); 
	int n,q,i,j,t,fu=0,k=0,book=0,x=0;
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&na[i]);
	}
	for(j=0;j<q;j++){
		scanf("%d %d",&k[j],&qa[j]);
		for(t=0;t<k[j];t++){
			o[j]=o[j]*10;
		}
	}
	for(j=0;j<q;j++){
		for(i=0;i<n;i++){
			if(na[i]==qa[j]||(na[i]-qa[j])%o[j]==0){
				jj[k]=na[i];
				k++;
				book++;
		}
			else fu++;
		}for(k=0;k<book;k++){
		x=xjb(jj[k],jj[k+1]);
		printf("%d",x);
	}
		for(t=0;t<fu;t++){
          printf("-1");
		  printf("\n");  
		}
	}
	

	return 0;
}

