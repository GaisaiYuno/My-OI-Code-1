#include<iostream>
#include<cstdio>
#include<set>
#define maxn 200000
using namespace std;
int n,m;
int a[maxn+5];
multiset<int,greater<int> > s;
int sum;
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	int del=0;
	for(int i=1;i<=n;i++){
		int tmp=sum+a[i];
		int ans=0;
		if(tmp>m){
			auto it=s.begin();
			while(tmp>m){
				ans++; 
				tmp-=(*it);
				it++; 
			}
		}	
		printf("%d ",ans+del);
		s.insert(a[i]);
		sum+=a[i];
		while(sum>m){//重要剪枝，如果现在的和就>m,无论之后的a[i]为何值，都需要删掉现在set中的一些元素，才能使得sum+a[i]<m 
			sum-=(*s.begin());
			s.erase(s.begin());
			del++;
		}
	}
}

