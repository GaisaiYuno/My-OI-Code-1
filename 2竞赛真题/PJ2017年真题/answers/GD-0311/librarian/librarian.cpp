#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

int n,q,x,y,a[1001];
char s[1001][11],s2[11];

int main(){
	freopen("librarian.in","r",stdin);
	freopen("librarian.out","w",stdout);
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		int cnt=0,x=a[i];
		while(x){cnt++;s[i][cnt]='0'+x%10;x=x/10;}
	}
	for(int i=1;i<=q;i++){
		scanf("%d%d",&y,&x);
		int cnt=0,ans=-1;
		while(x){cnt++;s2[cnt]='0'+x%10;x=x/10;}
		for(int i=1;i<=n;i++){
			bool tf=true;
			if(strlen(s[i]+1)<cnt)continue;
			for(int j=1;j<=cnt;j++)if(s[i][j]!=s2[j]){tf=false;break;}
			if(tf){ans=a[i];break;}
		}
		printf("%d\n",ans);
	}
}
