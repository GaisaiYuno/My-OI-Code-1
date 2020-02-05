//https://vjudge.net/problem/CodeChef-QCHEF
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define maxb 600
#define maxn 200000
using namespace std;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,vmax,m;
int a[maxn+5];

int bsz,bcnt;
int bel[maxn+5];
inline int lb(int id){
	return (id-1)*bsz+1;
}
inline int rb(int id){
	return id*bsz<=n?id*bsz:n;
}

int pre[maxn+5][maxb+5];//pre[i][j]��ʾֵi�ڵ�j�鼰֮����ֵ�����λ�� 
int nex[maxn+5][maxb+5];//nex[i][j]��ʾֵi�ڵ�j�鼰֮ǰ���ֵ�����λ�� 
int dp[maxb+5][maxb+5];//��[i,j]��֮������ֵ 
void ini(int n){
	bsz=sqrt(n);
	bcnt=1; 
	for(int i=1;i<=n;i++){
		bel[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	
	memset(pre,0x3f,sizeof(pre));
	for(int i=n;i>=1;i--) pre[a[i]][bel[i]]=i;
	for(int i=1;i<=n;i++) nex[a[i]][bel[i]]=i;
	for(int i=1;i<=vmax;i++){
		for(int j=bcnt;j>=1;j--) pre[i][j]=min(pre[i][j],pre[i][j+1]);
		for(int j=1;j<=bcnt;j++) nex[i][j]=max(nex[i][j],nex[i][j-1]);
	}
	for(int i=bcnt;i>=1;i--){
		for(int j=1;j<=bcnt;j++){
			dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
			for(int k=lb(i);k<=rb(i);k++) dp[i][j]=max(dp[i][j],nex[a[k]][j]-k);//nex[a[k][j],����a[k]�ڵ�j��֮ǰ������ֵ�λ��
		}
	}
}
int query(int l,int r){
	static int last[maxn+5];
	int L=bel[l]+1,R=bel[r]-1;
	int ans=dp[L][R];//����,�����˵㶼��[L,R]�ڵĴ� 
	for(int i=l;i<=rb(bel[l]);i++){
		if(!last[a[i]]){
			last[a[i]]=i;
			ans=max(ans,nex[a[i]][R]-i);//��˵���[L,R]�⣬�Ҷ˵���[L,R]�� 
		}
	}
	for(int i=lb(bel[r]);i<=r;i++){
		if(last[a[i]]) ans=max(ans,i-last[a[i]]);//��˵���Ҷ˵㶼������[L,R]��
		ans=max(ans,i-pre[a[i]][L]);//�Ҷ˵���[L,R]��,��˵���[L,R]�� 
	}
	for(int i=l;i<=rb(bel[l]);i++) last[a[i]]=0;
	return ans; 
}
int main(){
	int l,r;
	qread(n);
	qread(vmax);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	ini(n);
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		qprint(query(l,r));
		putchar('\n');
	} 
}

