//�ȿ���̰�ģ���Ȼk���ڵ��γ�һ����
//�������ֱ������Ȼֱ��Ӧ��ֻ������1��(��ı�Ӧ�������ٴ���)��������ֱ���ϵı߱�����2��
//�������״Ӧ������һ�����Ͻ����������
//��������DP
//��״̬��dp[x][i][j] j=0/1/2,��ʾ��xΪ����������ѡ��i���㣬i��������j��ֱ���Ķ˵�ʱ�ĳ���֮��
//״̬ת�Ʒ���:
//xΪy�ĸ��ף�jΪx����ȥ��y������������ѡ�ĵ�ĸ���,kΪy������ѡ�ĵ�ĸ��� 
//dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]+len*2);
//	x,y��������������ֱ������(x,y)���������ڲ��ıߣ�������2��
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][0]+dp[y][k][1]+len);
//	y����������ֱ����1���˵㣬��ֱ��һ������y����(x,y)��ֱ����ֻ����1��
//dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]+len*2);
//	x������(ȥ��y��������ͬ)����ֱ����1���˵㣬y������������ֱ���Ķ˵㣬ͨ����(x,y)��ֱ������������2��
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][2]+dp[y][k][0]+len*2);
//	x����������ֱ����2���˵㣬y������������ֱ���Ķ˵㣬ͨ����(x,y)��ֱ������������2��
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][0]+dp[y][k][2]+len*2);
//	y����������ֱ����2���˵㣬��ֱ��һ����������(x,y)����(x,y)����2��
//dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][1]+dp[y][k][1]+len);
//	x,y������������ֱ����1���˵㣬ֱ��һ����(x,y),��(x,y)����1��
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 3005
#define INF 0x3f3f3f3f3f3f3f3f
using namespace std;
inline int qread(){
	int x=0,sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar(); 
	}
	return x*sign;
}

int n,m;
struct edge {
	int from;
	int to;
	int next;
	long long len;
	edge() {

	}
	edge(int u,int v,long long w,int hd) {
		from=u;
		to=v;
		next=hd;
		len=w;
	}
} E[maxn<<1];
int head[maxn];
int ecnt=0;
void add_edge(int u,int v,long long w) {
	E[++ecnt]=edge(u,v,w,head[u]);
	head[u]=ecnt;
}

int sz[maxn];
long long dp[maxn][maxn][3];
void dfs(int x,int fa) {
	sz[x]=1;
	dp[x][1][0]=dp[x][1][1]=0;
	for(int i=head[x]; i; i=E[i].next) {
		int y=E[i].to;
		long long len=E[i].len;
		if(y!=fa) {
			dfs(y,x);
			//j����01�����еĵڶ��㣬Ϊ��ֹ�����Σ�����ѭ�� 
			for(int j=min(sz[x],m); j>=0; j--) {//jΪx����ȥ��y������������ѡ�ĵ�ĸ��� 
				for(int k=min(sz[y],m-j); k>=0; k--) {//kΪy������ѡ�ĵ�ĸ��� 
					dp[x][j+k][0]=min(dp[x][j+k][0],dp[x][j][0]+dp[y][k][0]+len*2);
					//x,y��������������ֱ������(x,y)���������ڲ��ıߣ�������2��
					dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][0]+dp[y][k][1]+len);
					//y����������ֱ����1���˵㣬��ֱ��һ������y����(x,y)��ֱ����ֻ����1��
					dp[x][j+k][1]=min(dp[x][j+k][1],dp[x][j][1]+dp[y][k][0]+len*2);
					//x����������ֱ����1���˵㣬y������������ֱ���Ķ˵㣬ͨ����(x,y)��ֱ������������2��
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][2]+dp[y][k][0]+len*2);
					//x����������ֱ����2���˵㣬y������������ֱ���Ķ˵㣬ͨ����(x,y)��ֱ������������2��
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][0]+dp[y][k][2]+len*2);
					//y����������ֱ����2���˵㣬��ֱ��һ����������(x,y)����(x,y)����2��
					dp[x][j+k][2]=min(dp[x][j+k][2],dp[x][j][1]+dp[y][k][1]+len);
					//x,y������������ֱ����1���˵㣬ֱ��һ����(x,y),��(x,y)����1��
				}
			}
			sz[x]+=sz[y];
		}
	}
}
int main() {
//	freopen("tree9.in","r",stdin); 
	int u,v;
	long long w;
	n=qread(); 
	m=qread();
	for(int i=1;i<n;i++){
		u=qread();
		v=qread();
		w=qread();
		add_edge(u,v,w);
		add_edge(v,u,w);
	}
	memset(dp,0x3f,sizeof(dp));
	dfs(1,0);
	long long ans=INF;
	for(int i=1;i<=n;i++){
		ans=min(ans,dp[i][m][2]);//����֮ǰ̰�ĵķ�����ֱ��һ��������k�����е�һЩ�� 
	}
	cout<<ans;
}
