//��������а�̣��������𣡣������� 
#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm> 
#define INF 0x3f3f3f3f
#define maxn 700 
using namespace std;
int n,m;
int g[maxn+5][maxn+5];
int invg[maxn+5][maxn+5];//��ͼ
int col[maxn+5];
int cnt[5];
void dfs(int x,int c){
	col[x]=c;
	cnt[c]++;
	for(int y=1;y<=n;y++){
		if(invg[x][y]){
			if(!col[y]) dfs(y,3-c);
			else if(col[y]==c){
				printf("-1\n");
				exit(0);
			}
		}
	} 
} 

inline int get_e(int x){
	return x*(x-1)/2;
}

int f[2][maxn+5];
//���Ʊ�������¼�ܲ��ܴճ�һ�����Ϊi����ͼ 
int main(){
	int u,v;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&u,&v);
		g[u][v]=1;
		g[v][u]=1; 
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(i!=j&&!g[i][j]) invg[i][j]=1;
		}
	}
	int now=1;
	f[1][0]=1;
	for(int i=1;i<=n;i++){
		if(!col[i]){
			cnt[1]=cnt[2]=0;
			dfs(i,1);
			//ͬһ������ͼ��ͨ�����ͬ��ɫ�ĵ㲻�ܷ�һ��
//			for(int j=n;j>=0;j--){
//				if(j-cnt[1]>=0) f[j]|=f[j-cnt[1]];
//				if(j-cnt[2]>=0) f[j]|=f[j-cnt[2]];
//			} 
			//ע�����ﲻ�ܵ���ѭ�����������f[j]����ѧ���ظ����� 
			for(int j=0;j<=n;j++){
				f[now^1][j+cnt[1]]|=f[now][j];
				f[now^1][j+cnt[2]]|=f[now][j];
			} 
			now^=1;
			 
		}
	}
	int ans=INF;
	for(int i=1;i<n;i++){
		if(f[now][i]) ans=min(ans,get_e(i)+get_e(n-i));
	}
	printf("%d\n",ans);
}
