#include <cstdio>
using namespace std;
int n,d,k,b,c,ans=0;
long long sum=0,sum1=0;
struct node{
	int x,s;
}a[500010];

int main(){
	freopen("jump.in","r",stdin);
	freopen("jump.out","w",stdout);
	scanf("%d%d%d",&n,&d,&k);
	for(int i=1;i<=n;i++){
		scanf("%d%d",&b,&c);
		a[i].x=b;a[i].s=c;if(c>0)sum+=c;sum1+=c;
	}
	if(sum<k)printf("-1\n");
	else {
		if(sum1>=k&&d==1)printf("0");
		else {
		    int now=0;
		    for(int i=1;i<=n;i++){
			    if(a[i].s>0){
				    int ss=a[i].x-now;
				    if(ss+1-2*d/2>ans)ans=ss+1-2*d/2;
			    }
		    }
		    printf("%d\n",ans);
	    }
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
