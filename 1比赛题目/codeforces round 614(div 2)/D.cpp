#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 100000
using namespace std;
typedef long long ll;
int n;
ll ax,ay,bx,by,xs,ys,t;
ll x[maxn+5],y[maxn+5];
ll dist(ll x1,ll y1,ll x2,ll y2){
	return abs(x1-x2)+abs(y1-y2);
}
int check(int k){
	ll T=t;
	ll nowx=xs,nowy=ys; 
	int cnt=0;
	for(int j=k;j>=0;j--){
		if(T>=dist(x[j],y[j],nowx,nowy)){
			cnt++;
			
			T-=dist(x[j],y[j],nowx,nowy);
			nowx=x[j];
			nowy=y[j];
		}else return cnt;
	}
	for(int j=k+1;j<=n;j++){
		if(T>=dist(x[j],y[j],nowx,nowy)){
			cnt++;
			T-=dist(x[j],y[j],nowx,nowy);
			nowx=x[j];
			nowy=y[j];
		}else return cnt;
	}
	return cnt;
}
int main(){
	cin>>x[0]>>y[0]>>ax>>ay>>bx>>by;
	cin>>xs>>ys>>t; 
	int i=1;
	while(1){
		x[i]=ax*x[i-1]+bx;
		y[i]=ay*y[i-1]+by;
		if(x[i]>t||y[i]>t) break;
		i++;
	}
	n=i;
	int ans=0;
	check(2);
	for(int i=0;i<=n;i++){
		ans=max(ans,check(i));
	}
	printf("%d\n",ans);
}

