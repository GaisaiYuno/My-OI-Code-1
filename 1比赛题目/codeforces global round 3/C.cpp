#include<iostream>
#include<cstdio>
#include<algorithm> 
#include<vector> 
#define maxn 300005
using namespace std;
//��x����λ��i�ķ���
//��x��x��Ӧ1��n�������ĸ����������ͺ��ĸ���)
//i��Ӧ��1��n��x��Ӧ��1��n����
int n; 
vector< pair<int,int> >ans;
int a[maxn];
int pos[maxn];//ֵΪi������λ�� 
inline int find(int x){
	if(2*(n-x)>=n) return n;
	else return 1;
} 
void change(int x,int y){
	ans.push_back(make_pair(x,y));
	swap(pos[a[x]],pos[a[y]]);
	swap(a[x],a[y]);
} 

int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pos[a[i]]=i;
	}
	for(int i=2;i<n;i++){
		int t=pos[i];
		change(t,find(t));
		if(find(t)!=find(i)) change(find(t),find(i));
		change(i,find(i)); 
	}
	if(a[1]!=1) change(1,n);
	printf("%d\n",ans.size());
	for(auto p : ans){
		printf("%d %d\n",p.first,p.second); 
	} 
}

