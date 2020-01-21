#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int e = 1e5+9;
int st[e][20],a[e],num[e],rt[e];
int n,q;
void init(){
	for(int i=1;i<=n;i++)st[i][0]=num[i];
	for(int j=1;j<=20;j++)
		for(int i=1;i+(1<<j)-1<=n;i++)
			st[i][j]=max(st[i][j-1],st[i+(1<<(j-1))][j-1]);
}
int query(int l,int r){
	if(l>r)return 0;
	int x,t1,t2;
	x=log2(r-l+1)/log2(2);
	return max(st[l][x],st[r-(1<<x)+1][x]);
}
int main()
{
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(i==1)num[i]=1;
		else if(a[i]==a[i-1])num[i]=num[i-1]+1;
		else num[i]=1;
	}
	for(int i=n;i>=1;i--){
		if(a[i]==a[i+1])rt[i]=rt[i+1];
		else rt[i]=i;
	} 
	init();
	while(q--){
		int l,r,t;
		scanf("%d%d",&l,&r);
		if(rt[l-1]==rt[l])t=min(r,rt[l])+1;
		else t=l;
		printf("%d\n",max(t-l,query(t,r)));
	}
	return 0;
}
