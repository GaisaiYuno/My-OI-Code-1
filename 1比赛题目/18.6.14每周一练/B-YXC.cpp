#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
#include<map>
using namespace std;
int n,m;
vector<int>A[100005];
bool done[100005];
bool huan=0;
bool aha[100005][2];
bool fi=0;
struct yxc{
	int aa,len;
	yxc(){
		aa=len=0;
	}
	yxc(int a,int b){
		aa=a,len=b;
	}
	friend bool operator<(yxc a,yxc b){
		if(a.aa!=b.aa) return a.aa<b.aa;
		else return a.len<b.len;
	}
};
map<yxc,yxc>M;
yxc ans;
void dfs(int aa,int len){
	if(fi) return;
	if(len>=1e6){
		huan=1;
		return;
	}
	bool flag=0;
	for(vector<int>::iterator i=A[aa].begin();i!=A[aa].end();i++){
		flag=1;
		if(done[*i]) huan=1;
		if(aha[*i][(len+1)&1]) continue;
		aha[*i][(len+1)&1]=1;
		done[*i]=1;
		M[yxc(*i,len+1)]=yxc(aa,len);
		dfs(*i,len+1);
		done[*i]=0;
	}
	if(!flag&&(len&1)){
		fi=1;
		ans=yxc(aa,len);
		return;
	}
}
void print(yxc aa){
	if(aa.len>=1) print(M[aa]);
	printf("%d ",aa.aa);
}
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		int a;
		scanf("%d",&a);
		while(a--){
			int b;
			scanf("%d",&b);
			A[i].push_back(b);
		}
	}
	int sta;
	scanf("%d",&sta);
	dfs(sta,0);
	if(fi){
		puts("Win");
		print(ans);
	}
	else if(huan) puts("Draw");
	else puts("Lose");
}

