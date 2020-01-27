//����Mi��ʾǰi�������������ǰi�������ĸ��� 
//ans=max(Mi) 
//����i,i+1֮��ķָ�㣬��ÿһ��˫��ð�ݣ�ʵ������ʹ��һ���ڷָ����ߵı�Ӧ���ұߵ��ܵ����ұߣ�ͬʱ��һ���ڷָ���ұߵı�Ӧ����ߵ��ܵ�����ߡ�
//Ҳ����˵ÿһ�����ʹ��Mi-1
//���������ĵ�i����a[i]
//��<a[i]������ԭλ�ò���BIT
//��ѯ1~i��ֵ���õ��ľ���ԭλ����i֮ǰ���������ǰi�������ĸ��� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int used[maxn];
struct node{
	int val;
	int id;
	node(){
		
	}
	node(int x,int i){
		val=x;
		id=i;
	}
	friend bool operator <(node x,node y){
		return x.val<y.val;
	}
}a[maxn];
int tree[maxn];
inline int lowbit(int x){
	return x&(-x);
}
void update(int x,int v){
	while(x<=n){
		tree[x]+=v;
		x+=lowbit(x);
	}
} 
int query(int x){
	int ans=0;
	while(x>0){
		ans+=tree[x];
		x-=lowbit(x);
	}
	return ans;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		a[i].id=i;
		scanf("%d",&a[i].val);
	}
	sort(a+1,a+1+n); 
	int ans=0;
	for(int i=1;i<=n;i++){
		update(a[i].id,1);
		ans=max(ans,i-query(i));//query(i)�����������ǰ���������iǰ������ĸ�������iȥ���͵õ��� 
	} 
	if(ans==0) ans=1;
	printf("%d\n",ans);
}
