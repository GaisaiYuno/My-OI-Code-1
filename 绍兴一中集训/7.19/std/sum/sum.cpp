#include<stdio.h>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 1000005

int i,j,n,num,S,p[N],vis[N],a[N],ans[N];

int fast(){
	int res=0,fl=1;
	char c=getchar();
	while(c<48||c>57){
		if(c=='-')fl=-1;
		c=getchar();
	}while(c>=48&&c<=57)res=res*10+c-48,c=getchar();
	return res*fl;
}

void write(int x){
	if(x>9)write(x/10);
	putchar(x%10+48);
}

int main()
{
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout);
	S=fast();
	n=fast();
	for(i=1;i<=n;i++)a[i]=fast(),p[a[i]]=1;
	for(i=1,j=1;i<=n;i++){
		if(vis[a[i]])continue;
		if(!p[S-a[i]+1])ans[++num]=S-a[i]+1;
			else{
				while(p[j]||p[S-j+1])j++;
				ans[++num]=j,ans[++num]=S-j+1;
				vis[S-a[i]+1]=1;j++;
			}
	}write(num);putchar(10);
	for(i=1;i<=num;i++)write(ans[i]),putchar(32);
	return 0;
}
