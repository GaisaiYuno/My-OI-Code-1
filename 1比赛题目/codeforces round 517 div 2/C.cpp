#include<iostream>
#include<cstdio>
#define maxn 2000005
#include<vector>
using namespace std;
long long a,b;
long long bin_search(){
	long long l=0,r=a+b,mid;
	long long ans=0; 
	while(l<=r){
		mid=(l+r)>>1;
		if(mid*(mid+1)/2<=a+b){
			ans=mid;
			l=mid+1;
		}else r=mid-1;
	}
	return ans;
}
int used[maxn];
vector<int>ans1;
vector<int>ans2;
int main(){
	cin>>a>>b;
	int n=bin_search();
	int sum=0;
	for(int i=n;i>=1;i--){
		if(sum+i<=a){
			used[i]=1;
			ans1.push_back(i);
			sum+=i;
		}else break;
	} 
	if(a-sum!=0&&!used[a-sum]){
		ans1.push_back(a-sum);
		used[a-sum]=1;
	}
	sum=0;
	for(int i=1;i<=n;i++){
		if(sum+i<=b){
			if(used[i]) continue;
			used[i]=1;
			ans2.push_back(i);
			sum+=i;
		}else break;
	}
	int x=ans1.size(),y=ans2.size();
	printf("%d\n",x);
	for(int i=0;i<x;i++) printf("%d ",ans1[i]);
	printf("\n");
	printf("%d\n",y);
	for(int i=0;i<y;i++) printf("%d ",ans2[i]);
}
