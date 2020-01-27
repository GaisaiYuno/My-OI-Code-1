#include<iostream>
#include<cstdio>
#include<cstring> 
#include<vector>
#define maxn 300000 
#define mod 1000000007 
using namespace std;
typedef long long ll; 
int n,m;
struct edge{
	int from;
	int to;
}a[maxn+5];
vector<int>E[maxn+5];
void add_edge(int u,int v){
	E[u].push_back(v);
	E[v].push_back(u);
}
int ans[maxn+5]; 
int mk[maxn+5];
int cnt[maxn+5];

void failed(){
	printf("-1\n");
	exit(0);
}
int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++){
		scanf("%d %d",&a[i].from,&a[i].to);
		if(a[i].from==1) mk[a[i].to]=1;
		if(a[i].to==1) mk[a[i].from]=1;
		add_edge(a[i].from,a[i].to);
	}
	//�����xѡ��ĳ��������ĵ�һ����,�ǰ���x��ֱ�������ĵ�ӽ�ȥҲ����
	//һ��ʼ��1��Ϊ��1��������ĵ� 
	for(int i=1;i<=m;i++) if(!mk[i]) ans[i]=1;	
	for(int i=1;i<=m;i++) mk[i]=0;
	if(E[1].size()==0) failed();
	
	//����1������ĳ������Ϊ��2��������ĵ�һ����
	//ͬ��Ѳ�ֱ�������ļӽ�ȥ 
	for(int i=1;i<=m;i++){
		if(a[i].from==E[1][0]) mk[a[i].to]=1; 
		if(a[i].to==E[1][0]) mk[a[i].from]=1; 
	}
	for(int i=1;i<=n;i++){
		if(!mk[i]){
			if(ans[i]!=1) ans[i]=2;
			else failed();
		}
	}
	//���ͬһ���������Ƿ��б� 
	for(int i=1;i<=m;i++){
		if(ans[a[i].from]==ans[a[i].to]) failed();
	}
	//ʣ�µĵ���Ϊ��3������ 
	for(int i=1;i<=n;i++){
		if(!ans[i]) ans[i]=3;
		cnt[ans[i]]++;
	}
	if(cnt[1]==0||cnt[2]==0||cnt[3]==0) failed();//�����Ƿ������÷ֳ�3������ 
	if(n*(n-1)/2-cnt[1]*(cnt[1]-1)/2-cnt[2]*(cnt[2]-1)/2-cnt[3]*(cnt[3]-1)/2 !=m) failed(); //����ܱ����Ƿ���� 
	for(int i=1;i<=n;i++){
		printf("%d ",ans[i]);
	} 
}

