#include<bits/stdc++.h>
using namespace std;
long long place[550000];
long long i=1,n,d,k,g=0,sum=0,far,nal=0;
int oil[440000];
int keys=1;
struct point{
	long long x,s;
}get[550000];
int main(){
	freopen("jump.in","r",stdin);
	scanf("%lld%lld%lld",&n,&d,&k);
	while(i<=n){
		scanf("%lld%lld",&get[i].x,&get[i].s);
		i++;
	}
	far=d;
	for(i=1;i<=n;i++){
		if(get[i].s>=0){
			sum+=get[i].s;
			oil[keys]=get[i].x;
			keys++;
		}
	}
	if(sum<k) g=-1;
	if(sum>=k){
		for(i=1;i<=keys-1;i++){
			if(oil[i+1]-oil[i]>far) far=oil[i+1]-oil[i];
			if(d-(oil[i+1]-oil[i])>far) far=d-(oil[i+1]-oil[i]);
		}
		g=far-d;
	}
/*	if(sum>k){
		while(sum>=k){
			
		}
	}*/
	freopen("jump.out","w",stdout);
	printf("%lld",&g);
}
