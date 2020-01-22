#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
using namespace std;

const int maxn=1000+2;
int n,q;
int book[maxn],want[maxn],request[maxn],tmp[maxn];
int w[maxn];
int i,j,k,l;
int x=0;
bool tf=false;

int main()
{
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d %d",&n,&q);
	for(i=0;i<n;i++){
		scanf("%d",&book[i]);
	}
	for(j=0;j<q;j++){
		scanf("%d %d",&w[j],&want[j]);
	}
	for(k=0;k<q;k++){
		tf=false;x=0;
		memset(tmp,0x7ffffff,sizeof(tmp));
		for(l=0;l<n;l++){
			request[l]=book[l]%((int)(pow(10,w[k])));
			if(request[l]==want[k]){
				tmp[++x]=book[l];
				tf=true;
			}
		}
		if(!tf)printf("-1\n");
		else{
			sort(tmp,tmp+x);
			printf("%d\n",tmp[1]);
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
