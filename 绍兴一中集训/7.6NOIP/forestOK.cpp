#include<iostream>
#include<cstdio>
#include<cstring>
#include<set> 
using namespace std;
int a[maxn+5],b[maxn+5];
int efa[maxn+5];//���ڵ�Ĺ��� 
multiset<ll>son[maxn+5];
multiset<ll>ans;//ȫ�����ֵ����Сֵ

int d[maxn+5];
//�Ѻ�c[i]=b[i]-d[i]*e[i]+sum(e[j])��������� 
ll  part1[maxn+5];//�洢 b[i]-d[i]*e[i]��ȥ�������ֵ
ll part2[maxn+5];//�洢 sum(e[i])��ȥ�������ֵ

void son_add(int x){
	son[x].insert(part1[x]+part2[x]);
}
void ans_add(int x){
	if(son[x].size()){
		ans.insert(*son[x].begin()+e[x]);
		ans.insert((*(--son[x].end())+e[x])); 
	}
}

void son_del(int x){
	son[a[x]].erase(son[a[x]].find(part1[x]+part2[x]));
}

void ans_del(int x){
	if(son[x].size()){
		ans.erase(ans.lower_bound(*son[x].begin()+e[x]));
		ans.erase(ans.lower_bound(*(--son[x].end())+e[x])); 
	}
}
int main(){
	int cmd,x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		d[a[i]]++;
		d[i]++;
	}
	for(int i=1;i<=n;i++) d[i]++;
	for(int i=1;i<=n;i++){
		e[i]=b[i]/d[i];
		part1[i]=b[i]-(d[i]-1)*e[i];//b[i]-d[i]*e[i],ȥ���˳���a[i]�Ĺ���
		part2[a[i]]+=e[i];
	}
	for(int i=1;i<=n;i++) son_add(i);
	for(int i=1;i<=n;i++) ans_add(i);
	for(int i=1;i<=m;i++){
		scanf("%d",&cmd);
		if(cmd==1){
			del(x,y);
		}
	}
}
