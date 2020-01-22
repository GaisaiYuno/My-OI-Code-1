#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#define maxn 10005
using namespace std;
int n;
int a[maxn];
struct edge{
	int from;
	int to;
	edge(){
		
	}
	edge(int u,int v){
		from=u;
		to=v;
	}
	void print(){
		printf("%d %d\n",from,to);
	}
};
vector<edge>ans;
vector<int>l;
int main(){
	int leaf=0;
	scanf("%d",&n);
	int sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		sum+=a[i];
		if(a[i]==1) leaf++;
		if(a[i]==0){
			printf("NO\n");
			return 0;
		}
	}
	if(sum<n*2-2){
		printf("NO\n");
		return 0;
	}
	
	for(int i=1;i<=n;i++){
		if(a[i]==1){
			l.push_back(i);
			a[i]=0;
		}
	}
	
	
	int begin=-1;
	if(l.size()){
		begin=l[l.size()-1];
		l.pop_back(); 
	}
	for(int i=1;i<=n;i++){
		if(a[i]>1){
			if(begin!=-1){
				a[begin]--;
				a[i]--;
				ans.push_back(edge(begin,i)); 
			}
			begin=i;
		}
	}
	int t=0;
	for(int i=n;i>=1;i--){
		while(l.size()&&a[i]>0){
			a[i]--;
			ans.push_back(edge(i,l[t++]));
			if(t>=l.size()) break;
		}
		if(t>=l.size()) break;
	}
	
	int d=(n-leaf)-1+min(2,leaf);
	if(ans.size()==n-1){
		printf("YES %d\n%d\n",d,n-1);
		for(int i=0;i<n-1;i++){
			ans[i].print();
		}
	}else{
		printf("NO\n");
	}
}
