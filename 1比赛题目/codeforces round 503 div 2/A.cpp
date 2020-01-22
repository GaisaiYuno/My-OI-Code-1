#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,h,a,b,k;
int ta,tb,fa,fb;
int main(){
	scanf("%d %d %d %d %d",&n,&h,&a,&b,&k);
	long long ans=0;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d %d",&ta,&fa,&tb,&fb);
		if(ta==tb&&fa==fb){
			printf("0\n");
			continue;
		}else if(ta==tb){
		    printf("%d\n",abs(fa-fb));
		    continue;
		}
		ans=0;
		ans+=abs(ta-tb);
		if(fa>b&&fb>b) ans+=(fa-b)+(fb-b);
		else if(fa<a&&fb<a) ans+=(a-fa)+(a-fb);
		else ans+=abs(fa-fb);
		printf("%I64d\n",ans);
	}
}

