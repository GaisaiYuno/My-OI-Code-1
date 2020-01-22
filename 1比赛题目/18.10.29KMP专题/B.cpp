#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
#define maxn 400005
using namespace std;
int n;
char a[maxn];
int next[maxn];
vector<int>ans;
void kmp(){
	memset(next,0,sizeof(next));
	next[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j>0&&a[i]!=a[j+1]) j=next[j];
		if(a[i]==a[j+1]) j++;
		next[i]=j;
	}
}
int main(){
	while(scanf("%s",a+1)!=EOF){
		n=strlen(a+1);
		kmp();
		ans.clear();
		for(int i=n;i;i=next[i]){
			ans.push_back(i);
		}
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++){
			printf("%d ",ans[i]);
		}
		printf("\n");
	}
}
