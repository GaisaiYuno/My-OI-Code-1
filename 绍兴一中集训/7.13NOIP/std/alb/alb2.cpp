#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=1<<9,inf=2e9;
int m,n,deep,i,j,k,v;
int a[N][N],f[N][N],ff[N][N],g[N][N];
int read(){
	char c=getchar();int k=0;for (;c<48||c>57;c=getchar());
	for (;c>47&&c<58;c=getchar()) k=(k<<3)+(k<<1)+c-48;return k;
}
int main(){
	freopen("alb.in","r",stdin);
	freopen("alb.out","w",stdout);
	m=read();n=1<<m;
	for (i=0;i<n;i++) for (j=0;j<n;j++)
		a[i][j]=read();
	for (deep=m,v=(n<<1)-2;deep--;v-=v&-v){
		for (i=0;i<n;i++) for (j=0;j<n;j++)
			ff[i][j]=f[i][j];
		int w=(v&-v)>>1,ww=w>>1;
		for (i=0;i<n;i++){
			int jst=(i&v)|((i&w)^w),jed=jst+w-1;
			int kst=(i&v)|(i&w)|((i&ww)^ww);
			int ked=kst+max(ww,1)-1;
			for (j=jst;j<=jed;j++){
				g[i][j]=inf;
				for (k=kst;k<=ked;k++)
					g[i][j]=min(g[i][j],f[i][k]+a[k][j]);
			}
		}
		for (i=0;i<n;i++){
			int jst=(i&v)|((i&w)^w),jed=jst+w-1;
			for (j=jst;j<=jed;j++){
				int kst=(j&v)|(j&w)|((j&ww)^ww);
				int ked=kst+max(ww,1)-1;
				f[i][j]=inf;
				for (k=kst;k<=ked;k++)
					f[i][j]=min(f[i][j],g[i][k]+ff[k][j]);
			}
		}
	}
	int w=n>>1,ans=inf;
	for (i=0;i<n;i++){
		int jst=(i&w)^w,jed=jst+w-1;
		for (j=jst;j<=jed;j++) ans=min(ans,f[i][j]);
	}
	printf("%d",ans);
}
