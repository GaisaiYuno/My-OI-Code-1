#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#define maxn 1005
using namespace std;
int n;
int a[maxn];
int b[maxn];
vector<int>ans;
int check(int len){
	for(int i=1;i<=n;i++){
		int t=i%len;
		if(t==0) t=len;
		if(b[i]!=b[t]) return 0;
	}
	return 1;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	for(int i=1;i<=n;i++){
		if(check(i)) ans.push_back(i);
	}
	int t=ans.size();
	printf("%d\n",t);
	for(int i=0;i<t;i++){
		printf("%d ",ans[i]);
	}
}
