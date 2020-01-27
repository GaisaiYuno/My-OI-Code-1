#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector> 
#define maxn 300005
using namespace std;
//把x换到位置i的方法
//把x与x对应1或n交换（哪个满足条件就和哪个换)
//i对应的1或n和x对应的1或n交换
int n; 
vector< pair<int,int> >ans;
int a[maxn];
int pos[maxn];//值为i的数的位置 
inline int find(int x){
	if(2*(n-x)>=n) return n;
	else return 1;
} 
void change(int x,int y){
	ans.push_back(make_pair(x,y));
	swap(pos[a[x]],pos[a[y]]);
	swap(a[x],a[y]);
} 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=2;i<n;i++){
		int t=pos[i];
		change(t,find(t));
		if(find(t)!=find(i)) change(find(t),find(i));
		change(i,find(i)); 
	}
	if(a[1]!=1) change(1,n);
	printf("%d\n",ans.size());
	for(auto p : ans){
		printf("%d %d\n",p.first,p.second); 
	} 
}

