//剪枝：
//1.知道总分和总场数，可以求出所有比赛中胜场和平场。搜索时超过这个值则返回0
//2.记忆化搜索，搜完某个人的所有场次后，如果后面所有队剩余分数从小到大排成的序列已经搜过了，那么可以直接返回上次搜到的值，这可以用Hash处理（100pts）
#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<algorithm>
#define maxn 12
#define base 19260817
#define mod 1000000007
using namespace std;
map<unsigned long long,long long>used;
int n;
int sum3,sum1;//3的场数和1的场数 
int a[maxn];//目标 
int b[maxn];//当前每行和 
int delta[maxn];//当前和与目标的差 
int cmp(int x,int y){
	return x>y;
}
long long dfs(int x,int y){
	if(x>=n) return 1;
	if(y>n){
		if(b[x]!=a[x]) return 0;//保证前x行一定是正好的 
		for(int i=1;i<=n;i++){
			delta[i]=a[i]-b[i];
		} 
		sort(delta+x+1,delta+n+1);
		unsigned long long hash=0;
		for(int i=x+1;i<=n;i++){//hash之后的行 
			hash=hash*base+delta[i];
		}
		if(used.count(hash)) return used[hash];
		else{
			used[hash]=dfs(x+1,x+2);
			return used[hash];
		}
	}
	long long ans=0;
	if(b[x]+3<=a[x]&&sum3){
		b[x]+=3;
		sum3--;
		ans+=dfs(x,y+1);
		b[x]-=3;
		sum3++;
	}
	if(b[y]+3<=a[y]&&sum3){
		b[y]+=3;
		sum3--;
		ans+=dfs(x,y+1);
		b[y]-=3;
		sum3++;
	}
	if(b[x]+1<=a[x]&&b[y]+1<=a[y]&&sum1){
		b[x]++;
		b[y]++;
		sum1--;
		ans+=dfs(x,y+1);
		b[x]--;
		b[y]--;
		sum1++;
	}
	return ans%mod;
}
int main(){
	int sum=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
	}
	sort(a+1,a+1+n,cmp);
	sum3=sum-n*(n-1);
	sum1=n*(n-1)/2-sum3;
	cout<<dfs(1,2)%mod;
}
