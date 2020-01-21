#include<iostream>
#include<cstdio>
#include<cmath>
#include<vector>
#include<algorithm>
#define maxn 10005
using namespace std;
int m;
long long p[maxn],c[maxn];
void divide(long long n){
	long long sq=sqrt(n);
	for(long long i=2;i<=sq;i++){
		if(n%i==0){
			p[++m]=i;
			c[m]=0;
			while(n%i==0){
				n/=i;
				c[m]++;
			}
		}
	}
	if(n>1){
		p[++m]=n;
		c[m]=1;
	}
}
bool is_prime(long long n){
	long long sq=sqrt(n);
	for(long long i=2;i<=sq;i++){
		if(n%i==0) return 0;
	}
	return 1;
}
bool judge(long long n){
	m=0;
	divide(n);
	if(m!=2) return 0;
	else{
		for(int i=1;i<=m;i++){
			if(c[i]!=1) return 0;
		}
		return 1;
	}
}

vector<pair<long long,long long> >ans; 
int main(){
	int cnt=0;
	const long long x=6541367ll;
	for(int i=0;i<=999;i++){
		if(judge(x*1000+i)){
//			ans.push_back(make_pair(p[1],p[2]));
			printf("#%d: %lld*%lld=%lld %lld\n",++cnt,p[1],p[2],p[1]*p[2],x*1000+i);
		}
	}
//	sort(ans.begin(),ans.end());
//	for(int i=0;i<ans.size();i++){
//		printf("#%d: %lld %lld %lld\n",i+1,ans[i].first,ans[i].second,ans[i].first*ans[i].second);
//	}
}

