#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 300000
#define maxm 300000 
using namespace std;
int n,m;
struct fenwick_tree{
	int c[maxn+maxm+5];
	inline int lowbit(int x){
		return x&(-x);
	}
	void update(int x,int v){
		for(int i=x;i<=n+m;i+=lowbit(i)) c[i]+=v;
	}
	int sum(int x){
		int ans=0; 
		for(int i=x;i>=1;i-=lowbit(i)) ans+=c[i];
		return ans;
	}
}T;

int minp[maxn+5],maxp[maxn+5];
int pos[maxn+maxm+5];
int main(){
	int x;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		pos[i]=i+m;
		T.update(pos[i],1);
		minp[i]=maxp[i]=i; 
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&x);
		minp[x]=1;//����յ�����Ϣ,��Сֵһ����1,������i 
		maxp[x]=max(maxp[x],T.sum(pos[x]));//i��λ��һ�����Լ��յ���Ϣ֮ǰ�ﵽ���ֵ
		T.update(pos[x],-1);
		pos[x]=m-i+1; //�Ƶ�ǰ�棬ע��Խ�����ŵĻ�����Խ����,������m-i+1 
		T.update(pos[x],1);
	}
	for(int i=1;i<=n;i++) maxp[i]=max(maxp[i],T.sum(pos[i]));//����һֱû���յ���Ϣ��,�������ֵ 
	for(int i=1;i<=n;i++) printf("%d %d\n",minp[i],maxp[i]);
}

