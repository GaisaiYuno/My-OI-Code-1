#include<iostream>
#include<cstring>
#define maxn 100000
#define INF 0x7f7f7f7f
using namespace std;
inline int fread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*sign;
}
int t,n;
int a[maxn],dp[maxn];
int main(){
	//freopen("data.txt","r",stdin);
    cin>>t;
    for(int cas=1;cas<=t;cas++){
        cin>>n;
        for(int i=1;i<=n;i++){
        	a[i]=fread();
		} 
        int max_sum,start,end;
        start=end=0;
        max_sum=-INF;
        memset(dp,0,sizeof(dp));
        for(int i=n;i>=1;i--){
        	dp[i]=-INF; 
        	dp[i]=max(a[i],dp[i+1]+a[i]);
        	if(dp[i]>=max_sum){
        		max_sum=dp[i];
        		start=i;
			}
		}
		int tmp=0;
		for(int i=start;i<=n;i++){
			tmp+=a[i];
			if(tmp==max_sum){
				end=i;
                break;
			}
		}
    	//printf("Case %d:\n",cas);
    	//printf("%d %d %d",max_sum,start,end);
    	//printf("\n\n");
    	printf("Case %d:\n%d %d %d\n",cas,max_sum,start,end);
		if(cas<t) printf("\n");
	}
}  
