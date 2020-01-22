#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#define maxn 40005
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign; 
}
inline void qread(long long &x){
	x=0;
	long long sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x*=sign; 
}

int n,m;
int bsz,bcnt;
int id[maxn];
int in[maxn];
int a[maxn];
inline int lb(int id){
	return bsz*(id-1)+1;
}
inline int rb(int id){
	return bsz*id>n?n:bsz*id;
}


long long f[maxn][2],g[maxn][2];
long long blo[maxn][5];
long long pre[maxn][5];
void work_dp(long long fv,int L,int R){
	f[L][0]=0;
	f[L][1]=fv;
	for(int i=L+1;i<=R;i++){
		f[i][0]=max(f[i-1][0],f[i-1][1]);
		f[i][1]=f[i-1][0]+a[i];
	}
}
void update(int x,long long v){
	a[x]=v;
	int t=id[x],l=lb(id[x]),r=rb(id[x]),len=r-l+1;

	
	if(len<=2){
		if(len==1) blo[t][1]=0;
		else blo[t][1]=a[l];
	}else{
		work_dp(0,l+1,r-1);
		blo[t][1]=max(f[r-1][0],f[r-1][1])+a[l];
	}
	
	if(len<=2){
		if(len==1) blo[t][2]=0;
		else blo[t][2]=a[r];
	}else{
		work_dp(a[l+1],l+1,r-1);
		blo[t][2]=f[r-1][0]+a[r];
	}
	
	if(len<=2){
		if(len==1) blo[t][3]=a[l];
		else blo[t][3]=0;
	}else{
		work_dp(0,l+1,r-1);
		blo[t][3]=a[l]+a[r]+f[r-1][0];
	}
	
	if(len<=2){
		if(len==1) blo[t][4]=0;
		else blo[t][4]=0;
	}else{
		work_dp(a[l+1],l+1,r-1);
		blo[t][4]=max(f[r-1][0],f[r-1][1]);
	}
}

long long query(){
	long long ans=0;
	for(int i=1;i<=bcnt;i++){
		pre[i][1]=max(pre[i-1][1],pre[i-1][4])+blo[i][1];
		pre[i][2]=max(max(pre[i-1][1],pre[i-1][2]),max(pre[i-1][3],pre[i-1][4]))+blo[i][2];
		pre[i][3]=max(pre[i-1][1],pre[i-1][4])+blo[i][3];
		pre[i][4]=max(max(pre[i-1][1],pre[i-1][2]),max(pre[i-1][3],pre[i-1][4]))+blo[i][4];
		ans=max(max(pre[i][1],pre[i][2]),max(pre[i][3],pre[i][4]));
	}
	
	return ans;
}
int main(){
	int x;
	long long y;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++){
		qread(in[i]);
	}
	bsz=sqrt(n);
	bcnt=1;
	for(int i=1;i<=n;i++){
		id[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	long long ans=0,now=0;
	for(int i=1;i<=n;i++) update(i,in[i]);
	for(int i=1;i<=m;i++){
		qread(x);
		qread(y);
		update(x,y);
		now=query();
		ans+=now;
//		printf("%d: %d\n",i,now);
	}
	printf("%lld\n",ans);
}
