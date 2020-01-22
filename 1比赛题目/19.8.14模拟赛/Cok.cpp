#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<cmath> 
#include<deque>
#define INF 1e9
#define eps 1e-6 
#define maxn 50000
#define maxlogn 20
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
int t;
int n,K,L,R;
int a[maxn+5];


//最大值最小值在两端的情况 
//最大值最小值在区间两端的时候显然更优 
// 01分数规划的套路，二分答案mid
//|a[i]-a[j]| >=mid(j-i+k)
//(1) (a[i]+mid*i)-(a[j]+mid*j)>=mid*k , 只要暴力枚举i,再在i右侧满足区间长度条件的范围内求一个值最小的j
//(2) (a[j]-mid*j)-(a[i]+mid*i)>=mid*k , 只要暴力枚举j,再在j左侧满足区间长度条件的范围内求一个值最小的j
//如果[i,j]内有比a[i]更大的a[k]怎么办？枚举到k的时候就会计入答案，且k为左端点的答案肯定比i优，会覆盖掉i为左端点的不合法情况 
int log_2[maxn+5]; 
double st1[maxlogn+5][maxn+5];//维护a[i]+mid*i的最小值 
double st2[maxlogn+5][maxn+5];//维护a[i]-mid*i的最小值 

double query1(int l,int r){
	int k=log_2[r-l+1];
	return min(st1[k][l],st1[k][r-(1<<k)+1]);
} 
double query2(int l,int r){
	int k=log_2[r-l+1];
	return min(st2[k][l],st2[k][r-(1<<k)+1]);
} 
bool check(double mid){
	for(int i=1;i<=n;i++) st1[0][i]=a[i]+mid*i;
	for(int i=1;i<=n;i++) st2[0][i]=a[i]-mid*i;
	for(int j=1;(1<<j)<=n;j++){
		for(int i=1;i+(1<<j)-1<=n;i++){
			st1[j][i]=min(st1[j-1][i],st1[j-1][i+(1<<(j-1))]);
			st2[j][i]=min(st2[j-1][i],st2[j-1][i+(1<<(j-1))]);
		}
	} 
	//st表把下标j放在前面常数优秀
	//如果写st[i][j],因为i在内层循环，会造成数组非最后一维的连续变化，由于数组的存储方式，寻址会TLE 
	double ans=-INF;
	for(int i=1;i<=n;i++){
		if(i+L-1<=n) ans=max(ans,a[i]+mid*i-query1(i+L-1,min(i+R-1,n))); 
	}
	for(int i=1;i<=n;i++){//这里的i对应的是上面的j 
		if(i-L+1>=1) ans=max(ans,a[i]-mid*i-query2(max(i-R+1,1),i-L+1));
	}
	return ans>=mid*K;
} 

//区间长度为L的时候，区间最大值不一定在左右端点，也可能成为最大答案 
//直接长度为L的滑块窗口求解 
double sp_solve(){
	deque<int>qmax;
	deque<int>qmin;
	double ans=-INF;
	for(int i=1;i<=n;i++){
		while(!qmax.empty()&&qmax.front()<i-L+1) qmax.pop_front(); 
		while(!qmin.empty()&&qmin.front()<i-L+1) qmin.pop_front(); 
		while(!qmax.empty()&&a[qmax.back()]<a[i]) qmax.pop_back();
		qmax.push_back(i);
		while(!qmin.empty()&&a[qmin.back()]>a[i]) qmin.pop_back();
		qmin.push_back(i);
		ans=max(ans,1.0*(a[qmax.front()]-a[qmin.front()])/(L-1+K));
	}
	return ans;
}
double bin_search(){
	double l=0,r=1000;
	double mid;
	double res=0; 
	while(r-l>=eps){
		mid=(l+r)/2;
		if(check(mid)){
			res=mid;
			l=mid+eps;
		}
		else r=mid-eps;
	}
	return res;
}
int main(){
	log_2[0]=-1;
	for(int i=1;i<=maxn;i++) log_2[i]=log_2[i>>1]+1;
	qread(t);
	while(t--){
		qread(n);
		qread(K);
		qread(L);
		qread(R);
		for(int i=1;i<=n;i++) qread(a[i]);
		double ans1=sp_solve();
		double ans2=bin_search();
		double ans=max(ans1,ans2); 
		printf("%.4f\n",ans);
	}

} 
/*
1 
5 4 1 1
4 3 5 3 1 
*/ 
