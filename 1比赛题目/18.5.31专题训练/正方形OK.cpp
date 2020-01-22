#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
using namespace std;
int T;
int n;
int a[25];
bool pd[25];
int sum;
bool mark;
int mx;
void dfs(int gs,int now,int wz){
//	pd[wz]=true;
	if(mark)return;
//	cout<<gs<<" "<<now<<" "<<wz<<endl;
		if(gs==3 && now+a[wz]==sum)
            mark=true;
		else{
				if(now+a[wz]==sum){
			for(int i=n;i>=1;i--){
				if(!pd[i] && a[i]<=sum){
					pd[i]=true;
					dfs(gs+1,0,i);
					pd[i]=false;
				}
	       	}
		}
		else{
			for(int i=n;i>=wz+1;i--){
			if(!pd[i] && now+a[i]+a[wz]<=sum){
				pd[i]=true;
				dfs(gs,now+a[wz],i);
				pd[i]=false;
			}
	}
		}
	}
}
int main(){
	scanf("%d",&T);
	while(T--){
	mx=0;
	memset(pd,false,sizeof(pd));
	scanf("%d",&n);
	sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	//	mx=max(mx,a[i]);
	//	a[i]=-a[i];
    }
    sort(a+1,a+n+1);
    if(sum%4!=0){
       printf("no\n");
	   continue; 	
	}
	else sum/=4;
	if(a[n]>sum){
		printf("no\n");
		continue;
	}
	mark=false;
//	cout<<sum<<endl;
	dfs(0,0,0);
	if(mark)puts("yes");
	else puts("no");
	}
}
/* 
1
19
3938 8208 1209 6983 8929 1941 445 8551 7206 4467 9743 5521 9707 9338 7243 4523 1455 3309 2520
*/  
