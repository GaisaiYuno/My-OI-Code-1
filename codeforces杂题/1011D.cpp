#include<iostream>
#include<cstdio>
using namespace std;
int m,n;
int ask(int x){
	printf("%d\n",x);
	fflush(stdout);
	int ans;
	scanf("%d",&ans);
	if(ans==0||ans==-2) exit(0);
	return ans;
} 
int lie[105];
int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++){
		if(ask(1)==-1){
			lie[i]=1;
		}
	} 
	int l=2,r=m;
	int cnt=0;
	while(l<=r){
		int mid=(l+r)>>1;
		int t=ask(mid);
		if(lie[cnt%n]) t=-t;
		if(t==1) l=mid+1;
		else r=mid-1;
		cnt++;
	}
	return 0;
}

