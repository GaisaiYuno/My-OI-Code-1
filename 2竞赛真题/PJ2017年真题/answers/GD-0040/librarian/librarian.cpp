#include<cmath>
#include<cstdio>
#include<algorithm>
using namespace std;
const int INF=10000001;
int n,q,code[1005],w,xq,minn,sign,a;
int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=0;i<n;i++){
		scanf("%d",&code[i]);
	}
	for(int i=0;i<q;i++){
		scanf("%d%d",&w,&xq);
		minn=INF; 
		for(int j=0;j<n;j++){
			sign=1;
			a=code[j]-xq;
			if(a<0)continue;
			for(int k=0;k<w;k++){
				if(a%10!=0){sign=0;break;}
				a/=10;
			}
			if(sign==1)minn=minn<code[j]?minn:code[j];
		}
		if(minn==INF)printf("-1\n");
		else printf("%d\n",minn);
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
