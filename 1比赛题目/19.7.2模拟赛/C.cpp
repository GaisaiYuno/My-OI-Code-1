//http://119.29.55.79/problem/3145
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200000
#define maxm 200000
#define maxlogn 20
#define INF 0x3f3f3f3f
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x/10>0) qprint(x/10);
		putchar(x%10+'0');
	}
}

int n,m,q;
int log2n;
int p[maxn+5];
int pnex[maxn+5];//��x��ѭ�������е���һ����
int a[maxm+5];

//�ҵ���x�������е�λ��i,p[i]->p[i+1]->p[i+2]������
int jump[maxm+5][maxlogn+5];//a[i]��2^j�ε���λ��
int last[maxm+5];//m->1����i,��a[i]��[i,m]����һ�γ��ֵ�λ��

int minpos[maxm+5];//��ʾ[i,n]�еĵ���n-1��������λ�õ���Сֵ

void ini_mul() {
	//��Щ���鶼Ҫmemset��INF��INF��ʾ�Ҳ�������������������0��������
	memset(last,0x3f,sizeof(last));
	for(int i=1; i<=n; i++) pnex[p[i]]=p[i%n+1];
	memset(jump,0x3f,sizeof(jump)) ;
	log2n=log2(n)+1;
	for(int i=m; i>=1; i--) {
		last[a[i]]=i;
		jump[i][0]=last[pnex[a[i]]];
	}
	for(int j=1; j<=log2n; j++) {
		for(int i=1; i<=m; i++) {
			if(jump[i][j-1]==INF) jump[i][j]=INF; // ��ֹԽ��
			else jump[i][j]=jump[jump[i][j-1]][j-1];
		}
	}
}
int query_mul(int x,int k) {
	for(int i=log2n; i>=0; i--) {
		if((1<<i)<=k) {
			k-=(1<<i);
			x=jump[x][i];
			if(x==INF) break;
		}
	}
	return x;
}

int ans[maxm+5];
int main() {
	int l,r;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1; i<=n; i++) {
		scanf("%d",&p[i]);
	}
	for(int i=1; i<=m; i++) {
		scanf("%d",&a[i]);
	}
	ini_mul();
	memset(minpos,0x3f,sizeof(minpos));
	for(int i=m; i>=1; i--) {
		minpos[i]=min(minpos[i+1],query_mul(i,n-1));
	}

	for(int i=1; i<=q; i++) {
		scanf("%d %d",&l,&r);
		if(minpos[l]<=r) ans[i]=1;
		else ans[i]=0;
	}
	for(int i=1; i<=q; i++) {
		printf("%d",ans[i]);
	}
}
