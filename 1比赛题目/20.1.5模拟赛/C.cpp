#include<iostream>
#include<cstdio>
#include<cstring> 
#define maxn 200
#define maxl 100000
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
typedef long long ll;
int n,m;
char a[maxn+5][maxl+5];
int len[maxn+5];
void get_nex(char *s,int n,int *nex){
	nex[1]=0;
	for(int i=2,j=0;i<=n;i++){
		while(j&&s[j+1]!=s[i]) j=nex[j];
		if(s[j+1]==s[i]) j++;
		nex[i]=j; 
	}
}
int kmp(char *s,int n,char *t,int m){
	static int nex[maxl+5];
	static int f[maxl+5];
	get_nex(t,m,nex);
	for(int i=1,j=0;i<=n;i++){
		while(j&&t[j+1]!=s[i]) j=nex[j];
		if(t[j+1]==s[i]) j++;
		f[i]=j;
	}
	if(f[n]==m) return m-nex[m];//两个相同串不能全部覆盖 
	else return m-f[n];
}

struct matrix{
	ll dist[maxn+5][maxn+5];//邻接矩阵的k次方就表示走k-1步
	//把乘法换成+,加法换成min,就能求出经过k个点的最短路
	void ini(){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++) dist[i][j]=INF;
		}
	}
	friend matrix operator * (matrix &p,matrix &q){
		matrix ans;
		ans.ini();
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					ans.dist[i][j]=min(ans.dist[i][j],p.dist[i][k]+q.dist[k][j]);
				}
			}
		}
		return ans;
	} 
}; 
matrix fast_pow(matrix &x,ll k){
	matrix ans=x;
	k--;
	while(k>0){
		if(k&1) ans=ans*x;
		x=x*x;
		k>>=1; 
	}
	return ans;
}
matrix d;
int main(){
//	freopen("data.txt","r",stdin);
	scanf("%d %d",&n,&m);
	ll minl=INF;
	for(int i=1;i<=n;i++){
		scanf("%s",a[i]+1);
		len[i]=strlen(a[i]+1);
		minl=min(minl,(ll)len[i]);
	}
	d.ini();
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			d.dist[i][j]=kmp(a[i],len[i],a[j],len[j]);
//			printf("%lld ",d.dist[i][j]);
		}
//		printf("\n");
	}
	if(m==1){
		printf("%lld\n",minl);
		return 0;
	}
	d=fast_pow(d,m-1);
	ll ans=INF;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			ans=min(ans,len[i]+d.dist[i][j]);
		}
	}
	printf("%lld\n",ans);
}


