#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
#define maxn 300005
int n,k;
int val[maxn];
int st[maxn][25];
int st1[maxn][25];
long double lg[maxn];
void read(int &x){
	x=0;char ch=getchar();bool f=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	if(f)x=-x;
}
void pre(){
	for(int i=1;i<=n;i++)st[i][0]=val[i],st1[i][0]=val[i];
	for(int j=1;j<=20;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st[i][j]=min(st[i][j-1],st[i+(1<<(j-1))][j-1]);
			st1[i][j]=max(st1[i][j-1],st1[i+(1<<(j-1))][j-1]);	
//			cout<<st[i][j]<<endl;		
		}
	}
}
int askmi(int l,int r){
//	log(r-l+1);
//	log(2);
	int t=lg[r-l+1]/lg[2];
	return min(st[l][t],st[r-(1<<t)+1][t]);
}
int askmx(int l,int r){
//	log(r-l+1);
//	log(2);	
	int t=lg[r-l+1]/lg[2];
	return max(st1[l][t],st1[r-(1<<t)+1][t]);	
}
bool check(int val){
	bool mark=false;
	for(int i=1;i+val-1<=n;i++){
		if(askmx(i,i+val-1)-askmi(i,i+val-1)<=k)mark=true;
		if(mark)break;
	}
	if(mark)return true;
	return false;
}
int main(){
	freopen("bed.in","r",stdin);
	freopen("bed.out","w",stdout);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++){
		read(val[i]);
	}
	for(int i=0;i<=n;i++){
		lg[i]=log(i);
	}
	pre();
	int x,y;
	int lx=1,rx=n;
	int mid;
	int ans=0;
//	cout<<check(1)<<endl;
	while(lx<rx){
		mid=lx+rx>>1;
		if(check(mid)){
			ans=max(ans,mid);
			lx=mid+1;
		}
		else{
			rx=mid;
		}
	}
	cout<<ans<<endl;
}
