//https://vjudge.net/problem/CodeChef-QCHEF
#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<algorithm>
#define maxn 200000
using namespace std;
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
inline void qprint(int x){
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

int n,vmax,m;
int a[maxn+5];

int bsz,bcnt;
int bel[maxn+5];
inline int lb(int id){
	return (id-1)*bsz+1;
}
inline int rb(int id){
	return id*bsz<=n?id*bsz:n;
}
void ini(int n){
	bsz=sqrt(n)+600;
	bcnt=1; 
	for(int i=1;i<=n;i++){
		bel[i]=bcnt;
		if(i%bsz==0) bcnt++;
	}
}

struct qtype{
	int l;
	int r;
	int id;
	friend bool operator < (qtype a,qtype b){
		return bel[a.l]<bel[b.l]||(bel[a.l]==bel[b.l]&&((bel[a.l]&1)?a.r<b.r:a.r>b.r));
	}
}q[maxn+5];
/*static */deque<int>pos[maxn+5];//ֵv���ֵ�λ�ã���С��������,Ī���ƶ������൱��ͷβ���в���

struct sqrtd{//ֵ��ֿ�,��O(1)����ɾ��,O(sqrt(n))ά��ȫ�����ֵ 
	int cnt[maxn+5];
	int sum[maxn+5];
	void insert(int val){
		cnt[val]++;
		sum[bel[val]]++;
		//��Ϊ����ά������r-l�����ֵ,��n,mͬ����,���Կ�����Ī�ӹ���bel���� 
	}
	void del(int val){
		cnt[val]--;
		sum[bel[val]]--;
	}
	int get_max(){
		for(int i=bel[n];i>=1;i--){
			//���ҵ����ķǿյĿ� 
			if(sum[i]){
				for(int j=rb(i);j>=lb(i);j--){
					if(cnt[j]) return j;
				} 
			}
		}
		return 0;
	}
}T; 
inline int get_d(int v){
	if(pos[v].empty()) return -1;
	else return pos[v].back()-pos[v].front();
}
#define PUSH_BACK 1
#define POP_BACK 2
#define PUSH_FRONT 3
#define POP_FRONT 4
void solve(int val,int index,int type){
	int pre=get_d(val);
	if(type==PUSH_BACK) pos[val].push_back(index); 
	else if(type==POP_BACK) pos[val].pop_back();
	else if(type==PUSH_FRONT) pos[val].push_front(index);
	else if(type==POP_FRONT) pos[val].pop_front();
	int nex=get_d(val);
	if(pre!=-1) T.del(pre);
	if(nex!=-1) T.insert(nex);
}
int ans[maxn+5];
int main(){
	qread(n);
	qread(vmax);
	qread(m);
	ini(max(vmax,n));
	for(int i=1;i<=n;i++) qread(a[i]);
	for(int i=1;i<=m;i++){
		qread(q[i].l);
		qread(q[i].r);
		q[i].id=i; 
	}
	sort(q+1,q+1+m);
	int l=1,r=0;
	for(int i=1;i<=m;i++){
		while(l>q[i].l){
			l--;
			solve(a[l],l,PUSH_FRONT); 
		} 
		while(r<q[i].r){
			r++;
			solve(a[r],r,PUSH_BACK);
		}
		while(l<q[i].l){
			solve(a[l],l,POP_FRONT);
			l++;
		}
		while(r>q[i].r){
			solve(a[r],r,POP_BACK);
			r--;
		}
		ans[q[i].id]=T.get_max();
	}
	for(int i=1;i<=m;i++){
		qprint(ans[i]);
		putchar('\n');
	}
}

