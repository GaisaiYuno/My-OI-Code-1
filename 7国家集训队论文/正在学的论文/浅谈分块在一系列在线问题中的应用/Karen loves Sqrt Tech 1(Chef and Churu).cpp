//http://119.29.55.79/problem/2001 
//https://vjudge.net/problem/CodeChef-FNCS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define maxn 200000
#define maxb 500
using namespace std;
typedef unsigned long long ll;
inline void qread(int &x){
	x=0;
	int sign=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') sign=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=x*10+c-'0';
		c=getchar();
	}
	x=x*sign;
}
inline void qprint(ll x){
	if(x<0){
		putchar('-');
		qprint(-x);
	}else if(x==0){
		putchar('0');
		return;
	}else{
		if(x>=10) qprint(x/10);
		putchar('0'+x%10);
	}
}
int n,m;
int a[maxn+5];
int L[maxn+5],R[maxn+5];

int bsz,bcnt;
int bel[maxn+5];
inline int lb(int id){
	return (id-1)*bsz+1;
}
inline int rb(int id){
	return id*bsz<=n?id*bsz:n;
}
struct sqrt1{//�ֿ�ά��a�����ǰ׺�� 
	ll sum[maxn+5];//sum[i]Ϊa�����ǰi��֮�ͣ����ǿ��ں� 
	ll mark[maxn+5];//ÿһ��ı�� 
	void add(int pos,int val){//��pos��֮���ǰ׺����val��Ӱ�� 
		for(int j=pos;j<=rb(bel[pos]);j++) sum[j]+=val;
		for(int j=bel[pos]+1;j<=bcnt;j++) mark[j]+=val;
	}	
	inline ll get_val(int pos){
		return sum[pos]+mark[bel[pos]];
	}
	inline ll query(int l,int r){
		return get_val(r)-get_val(l-1);
	}
}suma;

struct sqrt2{//ÿһ�鿪һ����ά�������ѯ��[l,r]����״�� 
	int sum[maxn+5];//λ��i�����ǵĴ��� 
	int mark[maxn+5];//�ӷ���� 
	void update(int l,int r,int val){
		if(bel[l]==bel[r]){
			for(int i=l;i<=r;i++) sum[i]+=val;
			return;
		}
		for(int i=l;i<=rb(bel[l]);i++) sum[i]+=val;
		for(int i=bel[l]+1;i<bel[r];i++) mark[i]+=val;
		for(int i=lb(bel[r]);i<=r;i++) sum[i]+=val; 
	}
	ll get_val(int pos){
		return sum[pos]+mark[bel[pos]];
	}
}cov[maxb+5];
ll ans[maxn+5];//ÿһ���ѯ�ʴ�֮�� 
void ini(){
	bsz=sqrt(n);
	bcnt=1; 
	for(int i=1;i<=n;i++){
		bel[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
	for(int i=1;i<=bcnt;i++){
		for(int j=lb(i);j<=rb(i);j++) cov[i].update(L[j],R[j],1);
	}
}
void update_val(int pos,int val){
	ll delta=val-a[pos];
	for(int i=1;i<=bcnt;i++) ans[i]+=delta*cov[i].get_val(pos); 
	//�Դ𰸵�Ӱ��Ϊ��λ�����ӵ�ֵ*��λ�ñ�ѯ�ʸ��ǵĴ��� 
	suma.add(pos,delta);
	a[pos]=val;
}
void update_seg(int pos,int l,int r){
	ans[bel[pos]]-=suma.query(L[pos],R[pos]);
	ans[bel[pos]]+=suma.query(l,r);
	cov[bel[pos]].update(L[pos],R[pos],-1);
	cov[bel[pos]].update(l,r,1);
	L[pos]=l;
	R[pos]=r;
}
ll query_ans(int l,int r){
	ll res=0;
	if(bel[l]==bel[r]){
		for(int i=l;i<=r;i++) res+=suma.query(L[i],R[i]);
		return res;
	}
	for(int i=l;i<=rb(bel[l]);i++) res+=suma.query(L[i],R[i]);
	for(int i=bel[l]+1;i<bel[r];i++) res+=ans[i];
	for(int i=lb(bel[r]);i<=r;i++) res+=suma.query(L[i],R[i]);
	return res;
} 

int main(){
	int cmd,p,l,r,x;
	static int tmp[maxn+5];
	qread(n);
	for(int i=1;i<=n;i++) qread(tmp[i]);
	for(int i=1;i<=n;i++){
		qread(L[i]);
		qread(R[i]);
	} 
	ini();
	for(int i=1;i<=n;i++) update_val(i,tmp[i]);
	qread(m);
	for(int i=1;i<=m;i++){
		qread(cmd);
		if(cmd==1){
			qread(p);
			qread(x);
			update_val(p,x); 
		}else if(cmd==2){
			qread(l);
			qread(r);
			qprint(query_ans(l,r));
			putchar('\n');
		}else{
			qread(p);
			qread(l);
			qread(r);
			update_seg(p,l,r);
		}
	}
}

