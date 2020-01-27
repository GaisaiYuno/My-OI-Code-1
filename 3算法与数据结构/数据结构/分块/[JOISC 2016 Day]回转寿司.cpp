#include<iostream>
#include<cstdio>
#include<cstring> 
#include<algorithm>
#include<cmath>
#include<queue>
#define maxn 400000
#define maxb 1000
using namespace std;
inline void qread(int &x) {
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(int x) {
	if(x<0) {
		putchar('-');
		qprint(-x);
	} else if(x==0) {
		putchar('0');
		return;
	} else {
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}

int n,m;
int a[maxn+5];

int bsz;
int bel[maxn+5];
inline int lb(int id){
	return bsz*(id-1)+1;
}
inline int rb(int id){
	return bsz*id>=n?n:bsz*id; 
}
priority_queue<int>num[maxb+5];//����ѣ��洢ÿһ���е��� 
priority_queue<int,vector<int>,greater<int> >mark[maxb+5] ;//С���ѣ��洢ÿһ�������滻��� 
//��С��������Ϊ�����е����ᱻ���Ȼ���С�ı��
void rebuild(int id){//�ع�ÿ���飬�����������滻���ǲ����滻����Ҫ����rebuild 
	while(!num[id].empty()) num[id].pop();
	for(int i=lb(id);i<=rb(id);i++){
		num[id].push(a[i]);
	}
}
void push_down(int id){
	if(!mark[id].empty()){
		for(int i=lb(id);i<=rb(id);i++){
			int v=mark[id].top();
			if(v<a[i]){
				swap(a[i],v);
				mark[id].pop();
				mark[id].push(v);//��a[i]��v���� 
			}
		}
		while(!mark[id].empty()) mark[id].pop();
		rebuild(id); 
	}
	
} 

int update(int l,int r,int A){
	push_down(bel[l]);//������������������Ʊ�� 
	for(int i=l;i<=min(r,rb(bel[l]));i++){
		if(A<a[i]) swap(a[i],A);
	}
	rebuild(bel[l]);
	for(int i=bel[l]+1;i<bel[r];i++){
		int v=num[i].top();
		if(v>A){ //������ֵ��AС���Ͳ��滻�� 
			num[i].pop();
			num[i].push(A);
			mark[i].push(A);
			swap(A,v);
			//�����޸ĵ�ʱ��ֻ��Ҫ�滻���ֵ��ʣ�µĲ���push_down��ʱ�����
		}
	}
	if(bel[l]!=bel[r]){
		push_down(bel[r]);
		for(int i=lb(bel[r]);i<=r;i++){
			if(A<a[i]) swap(a[i],A);
		}
		rebuild(bel[r]);
	}
	return A;
}
int main(){
	int l,r,A;
	qread(n);
	qread(m);
	for(int i=1;i<=n;i++) qread(a[i]);
	bsz=sqrt(n);
	for(int i=1;i<=n;i++){
		bel[i]=(i-1)/bsz+1;
		num[bel[i]].push(a[i]); 
	}
	for(int i=1;i<=m;i++){
		qread(l);
		qread(r);
		qread(A);
		if(l<=r){
			A=update(l,r,A);
		}else{
			A=update(l,n,A);
			A=update(1,r,A);
		}
//		printf("db:"); 
		qprint(A);
		putchar('\n');
	} 
}

