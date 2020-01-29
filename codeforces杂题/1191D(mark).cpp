#include<iostream>
#include<cstdio>
#include<map>
#include<algorithm>
#define maxn 100000 
using namespace std;
int n;
int a[maxn+5];
map<int,int>cnt;
bool check(){
	if(cnt.count(0)&&cnt[0]>1) return 0;
	for(auto x : cnt){//有出现次数超过2的 
		if(x.second>2) return 0;
	}
	int num=0;
	for(auto x : cnt){
		if(x.second>1) num++; 
	}
	if(num>=2) return 0;//有2个出现次数超过1的 
	for(auto x : cnt){
		if(x.second>1&&cnt.count(x.first-1)) return 0;
		//x出现>1次,x-1出现，无论先取x还是先取x-1都会造成相同 
	} 
	return 1;
} 
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		cnt[a[i]]++;
	}
	if(!check()){//检查初始情况
		printf("cslnb\n"); 
	}else{
		long long sum=0;
		//最优取法，从小取到大，第i堆取到i-1个，这样不会出现相同
		//因为是轮流取，再判断一下奇偶性，看看下一步谁取，取的就输 
		for(int i=1;i<=n;i++){
			sum+=a[i]-(i-1); 
		} 
		if(sum%2==1) printf("sjfnb\n");
		else printf("cslnb\n");
	}
	
}

