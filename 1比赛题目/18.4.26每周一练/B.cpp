#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 200005
using namespace std;
int b[maxn];
int n;
int main(){
	while(scanf("%d",&n)!=EOF){
		for(int i=1;i<=n;i++){
			scanf("%d",&b[i]);
		} 
		sort(b+1,b+1+n);
		int minb=b[1],maxb=b[n];
		int minb_cnt=0,maxb_cnt=0;
		for(int i=1;i<=n;i++){
			if(b[i]>minb) break;
			minb_cnt++;
		} 
		for(int i=n;i>=1;i--){
			if(b[i]<maxb) break;
			maxb_cnt++;
		} 
	    long long cnt=0;
		if(!(maxb_cnt==n&&minb_cnt==n))cnt=(long long)minb_cnt*maxb_cnt;
		else cnt=(long long)n*(n-1)/2; 
	    cout<<maxb-minb<<' '<<cnt<<endl;
	} 
}
