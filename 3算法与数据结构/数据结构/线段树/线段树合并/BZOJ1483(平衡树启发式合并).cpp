//https://www.luogu.org/problemnew/show/P3201
#include<iostream>
#include<cstdio>
#include<set>
#define maxn 1000005
using namespace std;
int n,m;
set<int>s[maxn]; //s[i]�洢��ɫi���ֵ�λ�� 
int a[maxn];
//�����1Ⱦ��2������size[1]>size[2]����ʱ����Ӧ�ý�2�ϲ���1�������� 
//�����Ժ�����ɫ2������û����ɫ2ֻ����ɫ1 
//��һ������f����ʾ����Ѱ��һ����ɫʱ��ʵ��Ӧ�����ĸ���ɫ�µ��������������������Ҫ����f[1]��f[2]
int f[maxn];
int ans=0;
void merge(int x,int y){
	if(x==y) return;
	if(s[f[x]].size()>s[f[y]].size()) swap(f[x],f[y]);
	x=f[x];
	y=f[y];
	for(set<int>::iterator it=s[x].begin();it!=s[x].end();it++){
		int p=*it;
		if(a[p-1]==y) ans--;
		if(a[p+1]==y) ans--;
		s[y].insert(p); 
	} 
	for(set<int>::iterator it=s[x].begin();it!=s[x].end();it++){
		int p=*it;
		a[p]=y;
	}
}
int main(){
	int cmd;
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		if(a[i]!=a[i-1]) ans++;
		s[a[i]].insert(i);
		f[a[i]]=a[i];
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==2){
			printf("%d\n",ans);
		}else{
			scanf("%d %d",&x,&y);
			merge(x,y);
		}
	}
}

