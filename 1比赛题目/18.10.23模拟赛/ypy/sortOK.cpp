//luogu 4372 
//�����i���ָ��߱�ʾ��i��i+1֮��ķָ���
//��ÿ���������γɷָ���֮ǰ�㽫���ϲ���1�Ĺ���
//��t[i]��ʾ��i���ָ��߳��ֵ�ʱ�䣬��ans=sum(max(t[i],t[i-1])
// ������μ����t[i]
//����ÿ����x����һ��ʼx�ұ����б�xС�������ƶ���x��߲Ż���ַָ���
//����ð��������ص㣬ÿ����ÿ�������ƶ�һλ��������ƶ�ʱ��t[i]Ϊx�ұ�С��x������x���ľ��� 
#include<iostream>
#include<cstdio>
#include<algorithm>
#define maxn 100005
using namespace std;
int n;
int a[maxn];
int t[maxn];
struct node{
	int x;
	int id;
	friend bool operator <(node a,node b){
		if(a.x==b.x) return a.id<b.id;
		return a.x<b.x;
	}
}b[maxn];
int main(){
//	freopen("sort5.in","r",stdin);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		b[i].x=a[i];
		b[i].id=i;
	}
	sort(b+1,b+1+n);
	int r=0;
	for(int i=1;i<=n;i++){
		r=max(r,b[i].id);
		t[i]=max(r-i,1);//����ЩС��x������x��ߣ�r-iΪ������������ 
	}
	long long ans=0;
	for(int i=1;i<=n;i++){
		ans+=max(t[i],t[i-1]);
	}
	cout<<ans;
}

