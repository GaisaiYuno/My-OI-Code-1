#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int n,m,f[100001],op[100001],w[100001];
bool ans[100001];
struct node{
	int s,d,num;
}q[100001];
bool cmp(node a,node b){
	return a.s>b.s;
}
int main(){
	freopen("snowboots.in","r",stdin);
	freopen("snowboots.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&f[i]);
	for(int i=1;i<n;i++)op[i]=i+1;
	for(int i=1;i<=m;i++)scanf("%d%d",&q[i].s,&q[i].d),q[i].num=i;
	sort(q+1,q+1+m,cmp);
	for(int i=1;i<=m;i++){
		for(int j=1;j;j=op[j]){
	//		cout<<j<<" ";
			while(f[op[j]]>q[i].s){
				op[j]++;
			}
			if(op[j]-j>q[i].d){
				ans[q[i].num]=1;break;
			}
		}
	//	cout<<endl;
		//if(!ans[q[i].num])ans[q[i].num]=1;
	}
	for(int i=1;i<=m;i++)cout<<(ans[i]^1)<<'\n';
}
//Ïß¶Î²¢ 
