/*
枚举区间左端点s 
如果给定左端点，则随着右端点递增，max值单调不下降，min值单调不上升
相交（相等）部分一定在中间
二分找出相等部分的左,右端点即可 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200005
#define maxlog 32
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
	x=x*sign;
}

inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}
	if(x==0){
		putchar('0');
		return;
	}
	if(x>0){
		if(x/10>0) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n;
int a[maxn],b[maxn];
int stmax[maxn][maxlog],stmin[maxn][maxlog];
void st_init(){
	memset(stmax,0xcf,sizeof(stmax));
	for(int i=1;i<=n;i++) stmax[i][0]=a[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			stmax[i][j]=max(stmax[i][j-1],stmax[i+(1<<(j-1))][j-1]);
		}
	}
	memset(stmin,0x7f,sizeof(stmin));
	for(int i=1;i<=n;i++) stmin[i][0]=b[i];
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<(j-1))<=n;i++){
			stmin[i][j]=min(stmin[i][j-1],stmin[i+(1<<(j-1))][j-1]);
		}
	}
}

int query_max(int l,int r){
	int k=log2(r-l+1);
	return max(stmax[l][k],stmax[r-(1<<k)+1][k]);
}

int query_min(int l,int r){
	int k=log2(r-l+1);
	return min(stmin[l][k],stmin[r-(1<<k)+1][k]);
}

int search_l(int s,int l,int r){//找最右端max-min>0的点,返回的答案+1即为右端点最小值 
	int ans=s-1,mid;//有可能s的右边全部等于0，所以答案初始化为s-1
	while(l<=r){
		mid=(l+r)>>1;
		if(query_min(s,mid)-query_max(s,mid)>0){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}

int search_r(int s,int l,int r){//找最右端max-min>=0的点 ，返回的答案为右端点最大值 
	int ans=s-1,mid;
	while(l<=r){
		mid=(l+r)>>1;
		if(query_min(s,mid)-query_max(s,mid)>=0){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}

int main(){
	int ans=0;	
	qread(n);
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=n;i++) qread(b[i]);
	st_init();
	for(int i=1;i<=n;i++){
		int l=search_l(i,i,n);
		int r=search_r(i,i,n);
		ans+=(r-l);
	}
	printf("%d\n",ans);
}
