//http://119.29.55.79/problem/312
//�ѻ����ƣ��ϻ�����
//���ѡ����ĳ������[l,r]����һ������һ����������[l,r]�ཻ�������У��Ҷ˵�������һ����
//Ȼ�����ҳ���i��������2^j������󣬵���ڼ������� 
#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm> 
#include<cmath>
#define maxn 200000
#define maxlogn 21
using namespace std;
int n,m;
struct node{
	int l;
	int r;
	int id;
	node(){
		
	}
	node(int L,int R,int i){
		l=L;
		r=R;
		id=i;
	}
	friend bool operator < (node p,node q){
		if(p.l==q.l) return p.r<q.r;
		else return p.l<q.l;
	} 
}a[maxn*2+5]; 
int nex[maxn*2+5][maxlogn+5];
int ans[maxn*2+5];
int sz;
int main(){
	int x,y;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d %d",&x,&y);
		if(x<y){
			a[++sz]=node(x,y,i);
			a[++sz]=node(x+m,y+m,i);
		}else{
			a[++sz]=node(x,y+m,i);
			a[++sz]=node(x+m,m*2,i);
		}
	}
	sort(a+1,a+1+sz);
	int l=1;
	for(int i=1;i<=sz;i++){
		//��Ϊ���䲻�����������l�������l1<l2,��r1һ��<r2������ᱻ����
		//����ֻҪ�ҵ����һ�� 
		while(l<sz&&a[l+1].l<=a[i].r) l++;
		nex[i][0]=l;
	}
	int log2n=log2(2*n);
	for(int j=1;j<=log2n;j++){
		for(int i=1;i<=sz;i++){
			nex[i][j]=nex[nex[i][j-1]][j-1];
		}
	} 
	for(int i=1;i<=n;i++){
		int x=i,sum=1;
		for(int j=log2n;j>=0;j--){
			if(nex[x][j]-i<n){//�������ݱ�֤һ���н⣬��n������һ���ܸ���ȫ�� 
				sum+=(1<<j);
				x=nex[x][j];
			}
		}	
		ans[a[i].id]=sum;
	}
	for(int i=1;i<=n;i++) printf("%d ",ans[i]);
}

