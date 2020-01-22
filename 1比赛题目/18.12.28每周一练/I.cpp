/*
Problem: ����Ⱦɫ[APIO2011]
Source:http://111.230.183.91/contest/14/problem/9
Algorithm:��򷽳̣��ߴ�Ȩ���鼯 
Description:
��ͼ���Է���
��i,jΪż����a[1][1]^a[i][1]^a[1][j]^a[i][j]=1
���� 		 a[1][1]^a[i][1]^a[1][j]^a[i][j]=0
ת��һ�±�� a[1][1]^a[i][1]^a[1][j]=1^a[i][j]
 			 a[1][1]^a[i][1]^a[1][j]=a[i][j]
����ֻҪȷ����1�к͵�1�оͿ�����
����1�к͵�1�п���n+m������
���ǿ���ö��a[1][1]��ֵ,Ȼ����ݹ�ϵȥ����������
��Ŀ�����������൱�ڸ���k�����̣�Ȼ���󷽳���������
ȷ����a[1][1]������a[1][1]=1�������a[i][j]���й�ϵ�� 
a[i][1]^a[1][j]=a[i][j]
a[i][1]^a[1][j]=1^a[i][j]
ͨ���ߴ�Ȩ���鼯��ά��,��Ȩd[x]Ϊ0,��ʾx��fa[x]��Ӧ��ֵ��� 
��󲢲鼯����b��fa[i]=i�ĵ㣬��˵����b�������Ƕ����ģ���������ȡ0/1,ȷ������b���Ϳ����Ƴ����б�����ֵ
����a[1][1]��ö��ʱ�Ѿ�ȷ�������Խ���2^(b-1)�� 
*/
#include<iostream>
#include<cstdio>
#include<cstring>
#define mod 1000000000
#define maxn 1000005
using namespace std;
int n,m,k;
inline long long fast_pow(long long x,long long k){
	long long ans=1;
	while(k>0){
		if(k&1) ans=ans*x%mod;
		x=x*x%mod;
		k>>=1;
	}
	return ans;
}
int x[maxn];
int y[maxn];
int c[maxn];
int fa[maxn];
int d[maxn];
int find(int x){
	if(x==fa[x]) return x;
	int root=find(fa[x]);
	d[x]^=d[fa[x]];
	fa[x]=root;
	return root;
}

long long solve(int x0){
	for(int i=1;i<=n+m;i++){
		fa[i]=i;
		d[i]=0;
	}
	fa[n+1]=1;
	if(x0==1){
		for(int i=1;i<=k;i++){
			if(x[i]>1&&y[i]>1) c[i]^=1;
		}
	}
	for(int i=1;i<=k;i++){
		if(!(x[i]==1&&y[i]==1)){
			int fx=find(x[i]);
			int fy=find(y[i]+n);
			int tmp=d[x[i]]^d[y[i]+n]^c[i];
			if(fx==fy){
				if((d[x[i]]^d[y[i]+n])!=c[i]) return 0;
			}else{
				fa[fy]=fx;
				d[fy]=tmp;
			}
		}
	}
	int block=0;
	for(int i=1;i<=n+m;i++){
		if(fa[i]==i) block++;
	}
	return fast_pow(2,block-1);
} 
int main(){ 
	int limit;
	scanf("%d %d %d",&n,&m,&k);
	limit=-1;
	for(int i=1;i<=k;i++){
		scanf("%d %d %d",&x[i],&y[i],&c[i]);
		if(x[i]%2==0&&y[i]%2==0) c[i]^=1;
		if(x[i]==1&&y[i]==1){
			limit=c[i];
		}
	}
	if(limit!=-1) printf("%lld\n",solve(limit));
	else{
		long long ans=0;
		for(int i=0;i<=1;i++) ans+=solve(i);
		ans%=mod;
		printf("%lld\n",ans);
	}
}

