#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct node{
	int a,b;
	int d;
}s[100005];
int cmp(node x,node y){
	return x.d>y.d;
}
int n;
long long m;
int main(){
	scanf("%d %I64d",&n,&m);
	long long sum=0;
	for(int i=1;i<=n;i++){
		scanf("%d %d",&s[i].a,&s[i].b);
		s[i].d=s[i].a-s[i].b;
		sum+=s[i].a;
	}
	sort(s+1,s+1+n,cmp);
	if(sum<=m){
		printf("0\n");
		return 0;
	}
	int ans=0;
	bool flag=false;
	for(int i=1;i<=n;i++){
		ans++;
		sum-=s[i].d;
		if(sum<=m){
			flag=true;
			break;
		}
	}
	if(!flag) printf("-1\n");
	else printf("%d\n",ans);
}
